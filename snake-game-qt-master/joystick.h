#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QObject>
#include "SDL2/SDL.h"
#include "SDL2/SDL_joystick.h"
#include "QDebug"
#include <QThread>
#include "snake.h"
#include <QTimer>

class joystick : public QObject
{
    Q_OBJECT
private:
    SDL_Joystick * joy;
    QTimer * timer;
    SDL_Event * event;
    Snake * s;
    int axisValue;
public:
    explicit joystick(QObject *parent = nullptr, Snake * s = nullptr);
    int getAxisValue();

signals:

public slots:
    void joystick_update();

};


#endif // JOYSTICK_H
