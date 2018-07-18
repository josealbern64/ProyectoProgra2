#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <iostream>
#include <QTimer>

#include "Vehicle.h"


int vehicleType;
Vehicle::Vehicle(QGraphicsItem* parent)
    : QGraphicsSvgItem(parent)
{
    // The name of the svg element
    vehicleType = qrand()%2;
    setElementId(QString("vehicle%1").arg(vehicleType));
}

void Vehicle::spawn(int lane)
{
    // The vehicle spawn in the specified lane (0 being the uppermost) and moves towards the other end
    qreal startX = -400;
    qreal endX = 1300;
    //to move to the other direction
    if(lane == 1)
    {
        startX = endX;
        endX = -400;
        setElementId(QString("vehicle%1").arg(vehicleType + 2));
    }
    QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");
    animation->setStartValue(QPointF(startX, 400 + (lane * 100)));
    animation->setEndValue(QPointF(endX,400 + (lane * 100)));
    animation->setDuration(2000);
    animation->start();
    QTimer* animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Vehicle::deleteLater);
    animationTimer->start(2000);

}
