#ifndef MENU_H
#define MENU_H

#include <QFrame>
#include <Game.h>
#include "Help.h"
namespace Ui {
class Menu;
}

class Menu : public QFrame
{
    Q_OBJECT
    Q_DISABLE_COPY(Menu)
public:
    explicit Menu(int &argc, char **argv);
    ~Menu();

private:
    Ui::Menu *ui ;
    /// Instance of the game
    Game*  game;
    /// Instance of the help page
    Help* help;

protected slots:
    /// Se invoca cuando el usuario presiona el boton de Singleplayer
    void startSinglePlayer();
    /// Se invoca cuando el usuario presiona el boton de Multiplayer
    void startMultiPlayer();
    /// Se invoca cuando el usuario presion el boton de Help
    void startHelp();
    /// Se invoca cuando el usuario presion el boton de Exit
    void exitGame();

};

#endif // MENU_H
