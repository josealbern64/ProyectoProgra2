#ifndef HELP_H
#define HELP_H

#include <QFrame>

namespace Ui {
class Help;
}

class Help : public QFrame
{
    Q_OBJECT
    Q_DISABLE_COPY(Help)

public:
    explicit Help(QWidget *parent = nullptr);
    ~Help();

private:
    Ui::Help *ui;

protected slots:

    /// Se invoca cuando el usuario presiona el boton Ok en la ventana de help
    void exitHelp();

};

#endif // HELP_H
