#ifndef GAMETIMER_H
#define GAMETIMER_H

#include <QGraphicsTextItem>

class GameTimer : public QGraphicsTextItem
{

//time remaining in seconds
int timeRemaining;

public:
  GameTimer(int initialTime, QGraphicsItem *parent = nullptr);
  ~GameTimer();

protected:
  void updateTime();

public slots:
  void decrease();
};

#endif // GAMETIMER_H
