#ifndef LOG_H
#define LOG_H

#include <QGraphicsSvgItem>

/**
 * @brief A log acts as a platform to keep the player from drowning
 */
class Log : public QGraphicsSvgItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Log)

  public:
    /// Constructor
    explicit Log(QGraphicsItem* parent = nullptr);
    /// Set the initial position of this item
    void setInitialPos();

};

#endif // LOG_H
