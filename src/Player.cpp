#include <QApplication>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <QTimer>
#include <QSoundEffect>
#include <QtMath>

#include "Player.h"

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


    // Do something if the spacebar is pressed
//	else if ( event->key() == Qt::Key_Space )
//		doSomething();

}

/*#include <iostream>
void Player::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	std::cerr << "player(" << event->pos().x() << ", " << event->pos().y() << ")\n";
}*/

void Player::move(double changeX, double changeY)
{
setPos( pos().x() + changeX, pos().y() + changeY );

    //Temporarily disabled animation to fix an issue
//    // Start a move animation from current starting point
//    QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");
//    animation->setStartValue(QPointF(pos().x(), pos().y()));

//    //
//    double targetX = this->pos().x()+changeX;
//    double targetY = this->pos().y()+changeY;
//    QPointF endPos(targetX, targetY);
//    animation->setEndValue(endPos);
//    animation->setDuration(75);

//    // Start the animation
//    animation->start();

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
            //scene()->removeItem(obstacle);
		}
	}
}
