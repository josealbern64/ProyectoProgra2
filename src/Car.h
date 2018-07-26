#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
  public:
    ///constructor
    Car(int lane = 0, qreal speedLevel = 0,QGraphicsItem* parent = nullptr);
    /// Creates a truck and that travels through the specified lane
    virtual void spawn() override;
};

#endif // CAR_H
