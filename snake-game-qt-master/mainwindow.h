#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QTimer>
#include <QPushButton>
#include "snake.h"
#include "fruit.h"
#include "grid.h"
#include "joystick.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    Snake* snake;
    Fruit* fruit;
    Grid *grid;
    joystick * my_joy;
    int delay=300;
protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent* event);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void refresh();
};

#endif // MAINWINDOW_H
