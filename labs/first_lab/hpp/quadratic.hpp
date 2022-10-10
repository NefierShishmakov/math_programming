#ifndef QUADRATIC_HPP
#define QUADRATIC_HPP

#include "equation.hpp"

namespace EquationSpace
{
    class Quadratic : public Equation
    {
        public:
            Quadratic();
            virtual ~Quadratic() {};
            Quadratic(long double epsilon, long double a, long double b, long double c);
            long double getFunctionValue(const long double value) override;
            long double getDiscriminant();
            long double getRoot(int sign);
        private:
            void setDiscriminant(long double epsilon);
        private:
            long double a;
            long double b;
            long double c;
            long double D;
    };
}

#endif