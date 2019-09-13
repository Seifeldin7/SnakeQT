#include "snake.h"

Snake::Snake(Grid grid): grid(grid)
{
    int centerX = grid.getMappedWidth()/2;
    int centerY = grid.getMappedHeight()/2;
    points.push_back(QPoint(centerX + 2, centerY));
    points.push_back(QPoint(centerX + 1, centerY));
    points.push_back(QPoint(centerX, centerY));
    points.push_back(QPoint(centerX - 1, centerY));
    direction = Right;
    pendingDirection = Right;
    growFlag = false;
}

QPoint Snake::getHead() {
    return *points.begin();
}

QPoint Snake::getTail() {
    return  *points.end();
}

size_t Snake::length() {
    return points.size();
}

bool Snake::move() {
    direction = pendingDirection;
    QPoint nextPoint = getNextPoint();
    if (!(nextPoint == *points.end() && !growFlag) && contains(nextPoint)) {
        return  false;
    }

    points.push_front(nextPoint);
    if (growFlag) {
        growFlag = false;
    } else {
        points.erase(std::prev(points.end()));
    }
    return true;
}

void Snake::grow() {
    growFlag = true;
}

void Snake::draw(QPainter *painter) {
    painter->setBrush(Qt::yellow);
    std::list<QPoint>::iterator it;
    for (it = points.begin(); it != points.end(); ++it) {
        painter->drawRect(grid.getRectOfPoint(it->x(), it->y()));
    }
    painter->setBrush(Qt::black);
}

void Snake::setDirection(Directions direction) {
    if (direction != (this->direction + 2)%4) {
        this->pendingDirection = direction;
    }
}

Directions Snake::getDirection() {
    return direction;
}

void Snake::setGrid(Grid grid) {
    this->grid = grid;
}

QPoint Snake::getNextPoint() {
    QPoint head = *points.begin();
    int gridWidth = grid.getMappedWidth();
    int gridHeight = grid.getMappedHeight();

    switch (direction) {
        case Top:
            return QPoint(head.x(), head.y() == 0? gridHeight - 1 : head.y() - 1);
        case Left:
            return QPoint(head.x() == 0? gridWidth - 1 : head.x() - 1, head.y());
        case Bottom:
            return QPoint(head.x(), (head.y()+1)%gridHeight);
        case Right:
            return QPoint((head.x() + 1)%gridWidth, head.y());
    }
    return QPoint();
}

bool Snake::contains(QPoint point) {
    std::list<QPoint>::iterator it;
    for (it = points.begin(); it != points.end(); ++it) {
        if (point.x() == it->x() && point.y() == it->y()) {
            return  true;
        }
    }
    return  false;
}
