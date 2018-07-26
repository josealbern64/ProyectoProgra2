#ifndef VEHICLE_H
#define VEHICLE_H

#include <QGraphicsSvgItem>

/**
 * @brief A vehicle kills the player on contact
 */
class Vehicle : public QGraphicsSvgItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Vehicle)

  protected:

    //The specified lane it iwll spawn on
    int lane;
    // The direction it will travel to
    QString direction;
    // The speed of the vehicle (proportional to score/difficulty)
    qreal speedLevel;
  public:
    /// Constructor
     Vehicle(int lane = 0, qreal speedLevel = 0,QGraphicsItem* parent = nullptr );
    /// Creates a vehicle and that travels through the specified lane
    virtual void spawn() = 0;

};

#endif // VEHICLE_H
