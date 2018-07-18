#ifndef GAME_H
#define GAME_H

#include <QApplication>

class QGraphicsScene;
class QSvgRenderer;
class QGraphicsView;
class Player;
class Score;
class Vehicle;
class GameTimer;

/**
	Game controller. An object that represents the game.
*/
class Game : public QApplication
{
	Q_DISABLE_COPY(Game)

  protected:
	// Manages graphic items. It is an invisible manager
	QGraphicsScene* scene;
	/// A visible widget that renders the scene
	QGraphicsView* view;
    /// Character that controls the player
	Player* player;
	/// Shows the score on the screen to the player
	Score* score;
    /// Shows the time remaining on the screen in seconds
    GameTimer* timeRemaining;
	/// Parsers the assets svg file
	QSvgRenderer* svgRenderer = nullptr;

    QTimer* timerVehicle0;
    QTimer* timerVehicle1;
    QTimer* timerVehicle2;

  public:
	/// Constructor
	Game(int &argc, char **argv, int flags = ApplicationFlags);
	/// Destructor
	~Game();
	/// Call this method instead of exec()
	int run();
	/// Play the given filename as background music
	void playBackgroundMusic(const QString& audioFilename);

  protected slots:
    /// Called each time a new enemy must be spawned
    void spawnVehicle0();
    void spawnVehicle1();
    void spawnVehicle2();
    void spawnLog();
};



#endif // GAME_H
