#ifndef FRUIT_H
#define FRUIT_H
#include "grid.h"
#include <QPainter>

class Fruit
{
public:
    Fruit(Grid grid, QPoint location);
    static Fruit* random(Grid grid);
    void draw(QPainter* painter);

    Grid getGrid();
    void setGrid(Grid grid);
    QPoint getLocation();

private:
    Grid grid;
    QPoint location;
};

#endif // FRUIT_H
