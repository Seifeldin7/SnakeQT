#include "fruit.h"
#include <QRandomGenerator>

Fruit::Fruit(Grid grid, QPoint location): grid(grid), location(location)
{

}

void Fruit::draw(QPainter *painter) {
    painter->setBrush(Qt::red);
    QRectF rect = grid.getRectOfPoint(location.x(), location.y());
    painter->drawRect(rect);
    painter->setPen(Qt::black);
}

Fruit* Fruit::random(Grid grid) {
    int x = QRandomGenerator::global()->bounded(1, grid.getMappedWidth() - 1);
    int y = QRandomGenerator::global()->bounded(1, grid.getMappedHeight() - 1);
    return new Fruit(grid, QPoint(x, y));
}

Grid Fruit::getGrid() {
    return grid;
}

void Fruit::setGrid(Grid grid) {
    this->grid = grid;
}

QPoint Fruit::getLocation() {
    return  location;
}
