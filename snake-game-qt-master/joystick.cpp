#include "joystick.h"

joystick::joystick(QObject *parent, Snake* s) : QObject(parent)
{
    this->s = s;
    SDL_Init(SDL_INIT_JOYSTICK);
    joy  = SDL_JoystickOpen(0);
    if(joy == NULL)
    {
        qDebug() <<"Joy Stick Not connected";
        exit(1);
    }
    qDebug()<<SDL_JoystickNumAxes(joy);
    /*while(1){
        SDL_JoystickUpdate();
        qDebug()<<SDL_JoystickGetAxis(joy,0);
        QThread::sleep(1);

    }*/
   // timer = new QTimer();
   // timer->setInterval(100);
    //timer->start();
    //connect(timer,SIGNAL(timeout()),this,SLOT(joystick_update()));
    event = new SDL_Event();
}
void joystick::joystick_update()
{
    //SDL_JoystickUpdate();
    //qDebug()<< "X= " << SDL_JoystickGetAxis(joy,0);
    while(SDL_PollEvent(event))
    {
        if(event->type == SDL_JOYAXISMOTION)
        {
            this->axisValue = event->jaxis.value;
            if(event->jaxis.value > 4000 && event->jaxis.axis==0  )
            {
                s->setDirection(Right);
            }
            else if(event->jaxis.value < -4000 && event->jaxis.axis==0)
            {
                s->setDirection(Left);

            }
            else if(event->jaxis.value > 4000 && event->jaxis.axis==1)
            {
            s->setDirection(Bottom);

            }
            else if(event->jaxis.value < -4000 && event->jaxis.axis==1)
            {
            s->setDirection(Top);

            }


           // qDebug()<<"Axis" << event->jaxis.axis << "value= " <<event->jaxis.value;
        }

        else if(event->type == SDL_JOYBUTTONDOWN)
        {
            qDebug()<<"Button" << event->jbutton.button << "presed" ;

        }
    }

}
int joystick::getAxisValue()
{
    return axisValue;
}
