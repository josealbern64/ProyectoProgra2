#include "Help.h"
#include "ui_Help.h"

Help::Help(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    // Si el usuario presiona el boton de ok en la ventana de help, se cierra
    connect(ui->closeButton, &QPushButton::clicked, this, &Help::exitHelp);
}

Help::~Help()
{
    delete ui;
}

void Help::exitHelp()
{
   this->close();
}
