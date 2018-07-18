#include <QColor>
#include <QFont>

#include "GameTimer.h"

GameTimer::GameTimer( int initialTime, QGraphicsItem *parent)
: QGraphicsTextItem(parent)
,timeRemaining(initialTime)
{
    setDefaultTextColor(Qt::blue);
    setFont(QFont("", 24));
    updateTime();
}

GameTimer::~GameTimer()
{
}

void GameTimer::decrease()
{
    --timeRemaining;
    updateTime();
}

void GameTimer::updateTime()
{
    setPlainText( QString("Time: %1").arg(timeRemaining) );
}
