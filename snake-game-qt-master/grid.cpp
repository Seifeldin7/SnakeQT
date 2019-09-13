#include "grid.h"

Grid::Grid(int width, int height, int mappedWidth, int mappedHeight):
    width(width), height(height), mappedWidth(mappedWidth), mappedHeight(mappedHeight)
{

}

int Grid::getWidth() {
    return width;
}

int Grid::getHeight() {
    return height;
}

int Grid::getMappedWidth() {
    return mappedWidth;
}

int Grid::getMappedHeight() {
    return mappedHeight;
}

QRectF Grid::getRectOfPoint(int x, int y) {
    double rectWidth = (double)width/mappedWidth;
    double rectHeight = (double)height/mappedHeight;
    double realX = x*rectWidth;
    double realY = y*rectHeight;
    return QRectF(realX, realY, rectWidth, rectHeight);
}
