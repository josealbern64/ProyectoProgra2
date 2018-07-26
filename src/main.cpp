#include "Menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    Menu menu(argc,argv);
    menu.show();

    return application.exec();
    // Represents the whole application
    /*Game game(argc, argv);
    return game.run();*/

}


