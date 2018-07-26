#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSvgRenderer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSoundEffect>
#include <QTime>
#include <QTimer>
#include <QSignalMapper>
#include <iostream>

#include "Game.h"
#include "Obstacle.h"
#include "Vehicle.h"
#include "Truck.h"
#include "Car.h"
#include "Motorbike.h"
#include "Player.h"
#include "Score.h"


Game::Game(int &argc, char **argv)
    : QApplication(argc, argv)
{
}

Game::~Game()
{
	delete this->scene;
	delete this->view;
}

int Game::run()
{
    // Init current lane
    currentLane = 0;
    // Init spawn rate of the vehicles
    spawnRate = 5000;
	// Init the random seed
	qsrand(QTime::currentTime().msec());

	// An invisible object that manages all the items
	this->scene = new QGraphicsScene();

    // A visible rectangle of the scene
	this->view = new QGraphicsView(this->scene);
  #if ! defined(Q_OS_ANDROID) && ! defined(Q_OS_IOS)
    this->view->resize(800, 600);
  #endif

    // Set a black color background or add an image as a background
    this->view->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    scene->addItem( new QGraphicsPixmapItem(QPixmap(":/Resources/background.png")) );

//	// The scene has infinite size, but we want it has the same size than the view
//	// This stops the weird behavior of the autoscroll feature of the view being smaller than the
//	// scene, because the scene auto-increases when objects are moved
    this->scene->setSceneRect( this->view->rect() );

//	// Disable scrollbars because they are not longer needed
    this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // A label to show the player's score
    this->score = new Score(tr("Score"), 0, Qt::blue);
    this->score->setPos(5, 0);
    this->scene->addItem(this->score);

//	// Load the graphic resources
    this->svgRenderer = new QSvgRenderer(QString("://Resources/assets.svg"), this);

    // Create the player control
    this->player = new Player();
    this->player->setSharedRenderer(svgRenderer);
    this->scene->addItem(this->player);
    this->player->setInitialPos();
    this->player->setFlag(QGraphicsItem::ItemIsFocusable);
    this->player->setFocus();

    // Spawns a vehicle periodically
    for(int index = 0; index < 8; ++index)
    {
        timerArray[index] = new QTimer(this);

        // Initial spawn of the vehicles
        timerArray[index]->start(1000+(500*index));
        connect(timerArray[index], &QTimer::timeout, this, &Game::spawnVehicle);

    }

    // Allow the game to know when the player has reached the goal
    connect(player, &Player::reachedGoal, score, &Score::increaseScore);
    connect(player, &Player::died, this, &Game::deathTimePenalty);

//	// Play background music
    playBackgroundMusic("MonkeysSpinningMonkeys-loop.mp3");

	// Show the view and enter in application's event loop
	this->view->show();
	return exec();
}

void Game::playBackgroundMusic(const QString& audioFilename)
{
	// We add the sound to a playlist
	QMediaPlaylist* playlist = new QMediaPlaylist();
	playlist->addMedia(QUrl("qrc:/Resources/" + audioFilename));

	// We add the playlist to a media player object
	QMediaPlayer* mediaPlayer = new QMediaPlayer(this);
	mediaPlayer->setPlaylist(playlist);

	// Play the playlist in an infinite loop
	playlist->setCurrentIndex(1);
	playlist->setPlaybackMode(QMediaPlaylist::Loop);

	// Set 2/3 of the volume and start playing the background music
	mediaPlayer->setVolume(67);
	mediaPlayer->play();
}

void Game::spawnVehicle()
{
     Vehicle* vehicle;
     int type = qrand()%3;
     switch(type)
     {
     case 0:
         vehicle = new Truck(currentLane%8,score->getScore(),nullptr);
         break;
     case 1:
         vehicle = new Car(currentLane%8,score->getScore(),nullptr);
         break;
     case 2:
         vehicle = new Motorbike(currentLane%8,score->getScore(),nullptr);
         break;
     }

    vehicle->setSharedRenderer(svgRenderer);
    scene->addItem(vehicle);
    vehicle->spawn();
    // Spawn rate of the vehicles in one lane increase by 10% every time the player scores
    timerArray[currentLane%8]->stop();
    timerArray[currentLane%8]->start((spawnRate*(pow(0.90,score->getScore()))));
    currentLane++;

}

void  Game::deathTimePenalty()
{
    this->player->setAlive(false);
    this->player->hide();
    penalty = new QTimer(this);
    this->connect(penalty, &QTimer::timeout,this, &Game::revivePlayer  );
    //3 seconds death time penalty
    this->penalty->start(3000);

}
void Game::revivePlayer()
{
    this->penalty->stop();
    this->player->show();
    this->player->setFocus();
    this->player->setAlive(true);
}



