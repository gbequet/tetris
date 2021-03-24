template <typename FUNC>
inline void Ball::move(const FUNC &f)
{
    f(x_, y_, vx_, vy_);
}
