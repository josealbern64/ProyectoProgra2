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

  public:
    /// Constructor
    explicit Vehicle(QGraphicsItem* parent = nullptr);
    /// Set the initial position of this item
    void setInitialPos();
    void spawn(int lane);

};

#endif // VEHICLE_H
