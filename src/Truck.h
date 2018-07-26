#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle
{
  public:
    ///constructor
    Truck(int lane = 0, qreal speedLevel = 0,QGraphicsItem* parent = nullptr );
    /// Creates a truck that travels through the specified lane
    virtual void spawn() override;
};

#endif // TRUCK_H
