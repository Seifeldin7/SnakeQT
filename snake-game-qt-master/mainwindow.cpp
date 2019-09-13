#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->resize(800, 600);
    timer = new QTimer();
    timer->setInterval(delay);
    connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    timer->start();

    grid = new Grid(this->width(), this->height());
    snake = new Snake(*grid);
    fruit = Fruit::random(*grid);
    my_joy = new joystick(this,snake);

}

MainWindow::~MainWindow()
{
    delete timer;
    delete fruit;
    delete snake;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e) {
    QPainter *painter = new QPainter(this);
    snake->draw(painter);
    fruit->draw(painter);
    delete painter;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Up:
            snake->setDirection(Top);
        break;
        case Qt::Key_Left:
            snake->setDirection(Left);
        break;
        case Qt::Key_Down:
            snake->setDirection(Bottom);
        break;
        case Qt::Key_Right:
            snake->setDirection(Right);
        break;
    }
   /* timer->stop();
    refresh();
    timer->start();*/
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    delete grid;
    grid = new Grid(event->size().width(), event->size().height());
    snake->setGrid(*grid);
    fruit->setGrid(*grid);
}

void MainWindow::refresh() {
    my_joy->joystick_update();

    delay = 400-abs(my_joy->getAxisValue()/100);



    if(delay <10)
    {
        delay = 1000;
    }

    timer->setInterval(delay);
    if (!snake->move()) {
        timer->stop();
        QMessageBox msgBox;
        msgBox.setText("Game Over");
        msgBox.exec();
        this->close();
        return;
    }

    QPoint head = snake->getHead();
    if (head.x() == fruit->getLocation().x() && head.y() == fruit->getLocation().y()) {
        if (snake->length() == ((grid->getMappedWidth()*grid->getMappedHeight()) - 1)) {
            QMessageBox msgBox;
            msgBox.setText("You Win");
            msgBox.exec();
            this->close();
            return;
        }

        snake->grow();
        delete fruit;
        fruit = Fruit::random(*grid);
    }

    if (snake->length()%5 == 0) {
        int newInterval = 100 + 200/(snake->length()/3);
        timer->stop();
        timer->start(newInterval);
    }
    this->repaint();

}
