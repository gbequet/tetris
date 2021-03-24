#ifndef _BALL_H_
#define _BALL_H_

class Ball
{
    public:
        Ball();

        // getters
        int X() const;
        int Y() const;

        // setters
        void set_pos(const double x, const double y);
        void set_speed(const double vx, const double vy);

        template <typename FUNC>
        inline void move(const FUNC &f);

    private:
        double x_;
        double y_;
        double vx_;
        double vy_;
};

#include "ball.inl"

#endif
