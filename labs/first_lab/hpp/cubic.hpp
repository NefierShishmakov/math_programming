#ifndef CUBIC_HPP
#define CUBIC_HPP

#include "equation.hpp"

namespace EquationSpace
{
    class Cubic : public Equation
    {
        public:
            Cubic();
            virtual ~Cubic() {};
            Cubic(long double a, long double b, long double c);
            long double getFunctionValue(const long double) override;
        private:
            long double a;
            long double b;
            long double c;
    };
}

#endif