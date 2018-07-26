#include <QApplication>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <QTimer>
#include <QSoundEffect>
#include <QtMath>
#include <iostream>
#include "Player.h"


 void Player::setAlive(bool state){alive = state;}

Player::Player()
{

	// Set graphic image
    //setElementId( QString("monster%1").arg( qrand() % 3 ) );
    setElementId(QString("frogUp"));
//	setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);

	// Pre-load the collision sound
    splatSound = new QSoundEffect(qApp);
    splatSound->setSource(QUrl("qrc:/Resources/splat.wav"));
    splatSound->setVolume(0.98);


	// Continuously check for collisions
	QTimer* collisionTimer = new QTimer(this);
	connect(collisionTimer, &QTimer::timeout, this, &Player::detectCollisions);
	collisionTimer->setInterval(25);
	collisionTimer->start();
}

Player::~Player()
{
    splatSound = nullptr;
}

void Player::setInitialPos()
{
	// Place the player in the middle bottom of the scene
	qreal x = (scene()->width() - boundingRect().width()) * 0.5;
    qreal y = (scene()->height() - boundingRect().height() -10);
	setPos(x, y);
}

void Player::keyPressEvent(QKeyEvent* event)
{
    static_cast<void>(event);
    // Move this object if arrow keys are pressed
    if ( event->key() == Qt::Key_Left )
    {
        this->setElementId(QString("frogLeft"));
        this-> move((scene()->width()/10)*-1,0);
    }
    else if ( event->key() == Qt::Key_Right )
    {
        this->setElementId(QString("frogRight"));this->setElementId(QString("frogRight"));
        this-> move((scene()->width()/10),0);
    }

    else if ( event->key() == Qt::Key_Up )
    {
        this->setElementId(QString("frogUp"));
        this->move(0,(scene()->height()/10)*-1);
    }
    else if ( event->key() == Qt::Key_Down )
    {
        this->setElementId(QString("frogDown"));
            this->move(0,(scene()->height()/10));
    }

}
#include "Game.h"
void Player::move(double changeX, double changeY)
{
    if(alive)
    {
        if(pos().x() + changeX > 0 && pos().x() + changeX < scene()->width()-20&&(pos().y() + changeY > 0 && pos().y() + changeY < scene()->height()))
            setPos( pos().x() + changeX, pos().y() + changeY );
        if(pos().y() + changeY < (scene()->height()/10)-50)
        {
            this->setInitialPos();
            emit reachedGoal();

        }
    }
}

#include "Vehicle.h"
void Player::detectCollisions()
{
	// Traverse all graphic items that are colliding with this
	const QList<QGraphicsItem*>& items = collidingItems();
	for ( QGraphicsItem* item : items )
	{
		// If a graphic item is an obstacle remove it from scene
        if ( Vehicle* vehicle = dynamic_cast<Vehicle*>(item) )
		{

			// Play the collision sound
            this->splatSound->play();
            this->setInitialPos();
            emit died() ;

		}
	}
}

