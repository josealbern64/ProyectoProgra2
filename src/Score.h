#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

/**
 * @brief A game label on the screen that shows a legend and a counter value
 * For example: to show the player's score, lifes, remaining time
 */
class Score : public QGraphicsTextItem
{
	Q_OBJECT
	Q_DISABLE_COPY(Score)

  protected:
	/// This scores measures something: health, power, bonus, points...
	QString legend;
    /// The amount scored, which also acts as game difficulty; the higher the score the faster the vehicles and their spawn rate
    size_t score;

  public:
	/// Constructor
	Score(const QString& legend, int initialScore, QColor color, QGraphicsItem *parent = nullptr);
	/// Destructor
	~Score();
	/// Returns a copy of the current score
    inline int getScore() const { return score; }
	/// Increase the score and updates the view



  protected:
	/// Updates the interface to match the int attribute score
	void updateScore();

  public slots:
     void increaseScore();
};

#endif // SCORE_H
