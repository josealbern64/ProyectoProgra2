#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "Vehicle.h"

class Motorbike : public Vehicle
{
  public:
    ///constructor
    Motorbike(int lane = 0, qreal speedLevel = 0,QGraphicsItem* parent = nullptr);
    /// Creates a motorbike that travels through the specified lane
    virtual void spawn() override;
};

#endif // MOTORBIKE_H
