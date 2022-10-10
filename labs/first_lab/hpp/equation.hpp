#ifndef EQUATION_HPP
#define EQUATION_HPP
#include <cmath>

namespace EquationSpace
{
    class Equation
    {
        public:
            virtual long double getFunctionValue(const long double param) = 0;
    };
}

#endif