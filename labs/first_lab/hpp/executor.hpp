#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <vector>
#include <iostream>
#include "quadratic.hpp"
#include "cubic.hpp"

namespace ExecutorSpace
{
    class Executor
    {
        public:
            Executor(long double epsilon, long double delta, long double a, long double b, long double c);
            ~Executor();
            void findSolutions();
            void printSolutions();
        private:
            long double findSolutionInBorders();
            void findConcreteSolution(const long double sol, const int shift);
            void setBorders(const long double start_value, const int shift);
        private:
            long double epsilon;
            long double delta;
            EquationSpace::Cubic *cubic;
            EquationSpace::Quadratic *quadratic;
            std::vector<long double> solutions;
            std::vector<long double> borders;
    };
}

#endif