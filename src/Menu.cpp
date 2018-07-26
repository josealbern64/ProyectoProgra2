#include "Menu.h"
#include "ui_Menu.h"
#include "Game.h"
#include "Help.h"
#include "ConnectDialog.h"

Menu::Menu(int &argc, char **argv)
    :game(new Game(argc,argv))
    ,help(new Help())
    ,ui(new Ui::Menu)
{
    // game = (new Game::Game(argc,argv))

    ui->setupUi(this);
    this->setWindowTitle("MultiFrogger");

    // Si el usuario presiona el boton de singleplayer, se inicia el juego
    connect(ui->singlePlayerButton, SIGNAL(clicked()), this, SLOT(startSinglePlayer()));
    // Si el usuario presiona el boton de multiplayer, se inicia el juego con red
    connect(ui->multiPlayerButton, SIGNAL(clicked()), this, SLOT(startMultiPlayer()));
    // Si el usuario presiona el boton de help, se abre otra ventana con instrucciones
    connect(ui->helpButton, SIGNAL(clicked()), this, SLOT(startHelp()));
    // Si el usuario presiona el boton de exit, se cierra la aplicacion
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exitGame()));
}

Menu::~Menu()
{
    delete ui;
}

void Menu::startSinglePlayer()
{
    this->hide();
    game->run();
}

void Menu::startMultiPlayer()
{
    ConnectDialog* dialog = new ConnectDialog(this);
    dialog->exec();
}
void Menu::startHelp()
{
    help->show();
}
void Menu::exitGame()
{
   this->close();
}
