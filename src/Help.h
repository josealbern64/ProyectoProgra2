#ifndef HELP_H
#define HELP_H

#include <QFrame>

namespace Ui {
class Help;
}

class Help : public QFrame
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = nullptr);
    ~Help();

private:
    Ui::Help *ui;
};

#endif // HELP_H
