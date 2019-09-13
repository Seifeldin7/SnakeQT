#ifndef GRID_H
#define GRID_H
#include <stddef.h>
#include <QRectF>

class Grid
{
public:
    Grid(int width, int height, int mappedWidth = 40, int mappedHeight = 40);
    int getWidth();
    int getHeight();
    int getMappedWidth();
    int getMappedHeight();
    QRectF getRectOfPoint(int x, int y);

private:
    int width;
    int height;
    int mappedWidth;
    int mappedHeight;
};

#endif // GRID_H
