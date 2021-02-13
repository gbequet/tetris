#include "ball.h"
#include <string>
#include <iostream>

Ball::Ball() : x(0), y(0), vx(40), vy(25)
{
    
}

double Ball::getPositionX() const
{
    return x;
}

double Ball::getPositionY() const
{
    return y;
}

double Ball::getSpeedVx() const
{
    return vx;
}

double Ball::getSpeedVy() const
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
