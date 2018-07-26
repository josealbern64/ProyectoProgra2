#include <QGraphicsScene>
#include <QTimer>

#include "AnimatedObject.h"

AnimatedObject::AnimatedObject(QGraphicsItem* parent)
	: QGraphicsSvgItem(parent)
	, timer( new QTimer(this) )
{
}

AnimatedObject::~AnimatedObject()
{
    this->destroy(true,true);
}

void AnimatedObject::destroy(bool removeFromScene, bool deleteObject)
{
	timer->stop();
	if (removeFromScene) scene()->removeItem(this);
	if (deleteObject) this->deleteLater();
}
