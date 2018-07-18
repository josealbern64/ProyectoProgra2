#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "Log.h"

Log::Log(QGraphicsItem* parent)
    : QGraphicsSvgItem(parent)
{
    // The name of the svg element
    setElementId("obstacle0");
}

void Log::setInitialPos()
{
    // We chose a random initial position within the screen
    qreal x = qrand() % int(scene()->width() - this->boundingRect().width());
    qreal y = qrand() % int(scene()->height() - this->boundingRect().height());
    QPointF endPos(x,y);
    setPos(endPos);
}
