#include "cubic.hpp"

namespace EquationSpace
{
    Cubic::Cubic(long double a, long double b, long double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    long double Cubic::getFunctionValue(const long double value)
    {
        return (value * value * value + this->a * value * value + this->b * value + this->c);
    }
}