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
#include "Log.h"
#include "Player.h"
#include "Score.h"
#include "GameTimer.h"


Game::Game(int &argc, char **argv, int flags)
	: QApplication(argc, argv, flags)
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

    // A label to show the player's time remaining
    this->timeRemaining = new GameTimer(120);
    this->timeRemaining->setPos(800,0);
    this->scene->addItem(this->timeRemaining);

    //Makes the timer count down
    QTimer* countdown = new QTimer(this);
    connect(countdown, &QTimer::timeout, timeRemaining, &GameTimer::decrease);
    countdown->start(1000);

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
    //ToDo usar solo un timer
    for(int index = 0; index < 8; ++index)
    {
        timerArray[index] = new QTimer(this);
        timerArray[index]->start(1000+(index * 500));
        connect(timerArray[index], &QTimer::timeout, this, &Game::spawnVehicle);
    }

   /* connect(timerArray[0], &QTimer::timeout, this, &Game::spawnVehicle0);
    connect(timerVehicle1, &QTimer::timeout, this, &Game::spawnVehicle1);
    connect(timerVehicle2, &QTimer::timeout, this, &Game::spawnVehicle2);
    timerVehicle0->start(0);
    timerVehicle1->start(1000);
    timerVehicle2->start(2000);
    //connect(player, &Player::incScore, this, &Score::increaseScore);*/

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

//ToDo hacer con solo un metodo
void Game::spawnVehicle()
{
    Vehicle* vehicle = new Vehicle();
    vehicle->setSharedRenderer(svgRenderer);
    scene->addItem(vehicle);
    vehicle->spawn(currentLane%8);
    timerArray[currentLane%8] -> stop();
    timerArray[currentLane%8] -> start(500 + (qrand()%1500));
    currentLane++;

}



