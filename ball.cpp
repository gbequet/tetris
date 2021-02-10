#include "ball.h"
#include <string>
#include <iostream>

Ball::Ball()
{
    x = 0;
    y = 0;
    vx = 40;
    vy = 25;
}

double Ball::getPositionX()
{
    return x;
}

double Ball::getPositionY()
{
    return y;
}

double Ball::getSpeedVx()
{
    return vx;
}

double Ball::getSpeedVy()
{
    return vy;
}

void Ball::moveX(double u)
{
    x += u;
}

void Ball::moveY(double u)
{
    y += u;
}

void Ball::changeSpeedX(double u)
{
    vx += u;
}

void Ball::changeSpeedY(double u)
{
    vy += u;
}
