#ifndef _BALL_H_
#define _BALL_H_

class Ball
{

public:
    Ball();

    // getters
    double getPositionX() const;
    double getPositionY() const;
    double getSpeedVx() const;
    double getSpeedVy() const;

    void moveX(double u);
    void moveY(double u);
    void changeSpeedX(double u);
    void changeSpeedY(double u);


private:
    double x;
    double y;
    double vx;
    double vy;
    int gravity;
};

#endif
