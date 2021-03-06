#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <iostream>
#include <QTimer>
#include <math.h>
#include "Motorbike.h"

Motorbike::Motorbike(int lane, qreal speedLevel,QGraphicsItem* parent):Vehicle(lane,speedLevel, parent)
{
    direction = "Right";
}

void Motorbike::spawn()
{
    qreal vehicleDuration = 3000;
    /// The motorbike spawn in the specified lane (0 being the uppermost) and moves towards the other end
    /// startX and endX are relative to their dimensions and makes sure the vehicles start and end outside the view
    qreal startX = -75;
    qreal endX = 975;
    //to move to the other direction
    if(lane%2 ==  1)
    {
        startX = endX;
        endX = -75;
        direction = "Left";

    }
    // The name of the svg element
    setElementId(QString("motorbike")+direction);
    QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");
    animation->setStartValue(QPointF(startX,(scene()->height()/10 + (lane * scene()->height()/10))));
    animation->setEndValue(QPointF(endX,(scene()->height()/10 + (lane * scene()->height()/10))));
    //vehicles travel 5% faster each time the player scores

    qreal difficulty = vehicleDuration*(pow(0.95,speedLevel));
    if(difficulty > 0)
        animation->setDuration(difficulty);
    animation->start();
    QTimer* animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Vehicle::deleteLater);
    animationTimer->start(difficulty);

}
