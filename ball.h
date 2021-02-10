#ifndef _BALL_H_
#define _BALL_H_

class Ball
{

public:
    Ball();

    // getters
    double getPositionX();
    double getPositionY();
    double getSpeedVx();
    double getSpeedVy();

    void moveX(double u);
    void moveY(double u);
    void changeSpeedX(double u);
    void changeSpeedY(double u);

private:
    double x;
    double y;
    double vx;
    double vy;
};

#endif
