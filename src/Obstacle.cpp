#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "Obstacle.h"

Obstacle::Obstacle(QGraphicsItem* parent)
	: QGraphicsSvgItem(parent)
{
	// The name of the svg element
	setElementId("obstacle0");
}

void Obstacle::setInitialPos()
{
	// We chose a random initial position within the screen
    qreal x = qrand() % int(scene()->width() - this->boundingRect().width());
    qreal y = qrand() % int(scene()->height() - this->boundingRect().height());
    QPointF endPos(x,y);
	setPos(endPos);
}

#include <iostream>
void Obstacle::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	std::cerr << "obstacle(" << event->pos().x() << ", " << event->pos().y() << ")\n";
}
