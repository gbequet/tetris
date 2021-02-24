#include "ball.h"
#include <string>
#include <iostream>

Ball::Ball() : x_(0), y_(0), vx_(40), vy_(25)
{

}

int Ball::X() const
{
    return int(x_);
}

int Ball::Y() const
{
    return int(y_);
}

void Ball::set_pos(const double x, const double y)
{
    x_ = x;
    y_ = y;
}

void Ball::set_speed(const double vx, const double vy)
{
    vx_ = vx;
    vy_ = vy;
}
