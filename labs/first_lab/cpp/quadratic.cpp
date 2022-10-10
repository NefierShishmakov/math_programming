#include "quadratic.hpp"

namespace EquationSpace
{
    Quadratic::Quadratic(long double epsilon, long double a, long double b, long double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->setDiscriminant(epsilon);
    }

    long double Quadratic::getFunctionValue(const long double value)
    {
        return (this->a * pow(value, 2) + this->b * pow(value, 1) + this->c);
    }

    void Quadratic::setDiscriminant(long double epsilon)
    {
        long double dis = this->b * this->b - 4 * this->a * this->c;
        long double condition = epsilon * epsilon * this->a * this->a;

        if (dis < -condition)
        {
            this->D = -1;
        }
        else if (dis > condition)
        {
            this->D = dis;
        }
        else
        {
            this->D = 0;
        }
    }

    long double Quadratic::getRoot(int sign)
    {
        return (-b + sign * sqrt(this->D)) / (2 * this->a);
    }

    long double Quadratic::getDiscriminant()
    {
        return this->D;
    }
}