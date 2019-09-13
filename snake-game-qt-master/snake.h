#ifndef SNAKE_H
#define SNAKE_H

#include "direction.h"
#include "grid.h"
#include <list>
#include <QPoint>
#include <QPainter>


class Snake
{
public:
    Snake(Grid grid);
    QPoint getHead();
    QPoint getTail();
    size_t length();
    bool move();
    void grow();
    void draw(QPainter* painter);
    void setDirection(Directions direction);
    void setGrid(Grid grid);
    Directions getDirection();

private:
    std::list<QPoint> points;
    Directions direction;
    Grid grid;
    bool growFlag;
    QPoint getNextPoint();
    bool contains(QPoint point);
    Directions pendingDirection;
};

#endif // SNAKE_H
