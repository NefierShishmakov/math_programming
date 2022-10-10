#include "executor.hpp"

namespace ExecutorSpace
{
    Executor::Executor(long double epsilon, long double delta, long double a, long double b, long double c)
    {
        this->epsilon = epsilon;
        this->delta = delta;
        this->cubic = new EquationSpace::Cubic(a, b, c);
        this->quadratic = new EquationSpace::Quadratic(epsilon, 3, 2 * a, b);
        this->borders.resize(2);
    }

    Executor::~Executor()
    {
        delete this->cubic;
        delete this->quadratic;
    }

    void Executor::setBorders(const long double start_value, const int shift)
    {
        long double res = start_value;

        while (true)
        {
            res += shift * this->delta;

            if (shift == 1 && this->cubic->getFunctionValue(res) > 0)
            {
                this->borders[0] = res - this->delta;
                this->borders[1] = res;
                break;
            }
            else if (shift == -1 && this->cubic->getFunctionValue(res) < 0)
            {
                this->borders[0] = res;
                this->borders[1] = res + this->delta;
                break;
            }
        }
    }

    long double Executor::findSolutionInBorders()
    {
        long double possible_solution;

        while (true)
        {
            possible_solution = (this->borders[0] + this->borders[1]) / 2;
            long double value = std::abs(this->cubic->getFunctionValue(possible_solution));

            if (std::abs(this->cubic->getFunctionValue(borders[0])) < epsilon)
            {
                possible_solution = borders[0];
                break;
            }
            else if (std::abs(this->cubic->getFunctionValue(borders[1])) < epsilon)
            {
                possible_solution = borders[1];
                break;
            }
            else if (value < this->epsilon)
            {
                break;
            }
            
            if (this->cubic->getFunctionValue(this->borders[0]) * this->cubic->getFunctionValue(possible_solution) <= 0)
            {
                this->borders[1] = possible_solution;
            }
            else if (this->cubic->getFunctionValue(possible_solution) * this->cubic->getFunctionValue(this->borders[1]) <= 0)
            {
                this->borders[0] = possible_solution;
            }

        }

        return possible_solution;
    }

    void Executor::findConcreteSolution(const long double sol, const int shift)
    {
        this->setBorders(sol, shift);
        this->solutions.push_back(this->findSolutionInBorders());
    }

    void Executor::findSolutions()
    {
        long double D = this->quadratic->getDiscriminant();

        if (D <= 0)
        {
            long double f_0 = this->cubic->getFunctionValue(0);

            if (std::abs(f_0) < this->epsilon)
            {
                this->solutions.push_back(0);
            }
            else
            {
                int shift = (f_0 < -this->epsilon ? 1: -1);
                this->findConcreteSolution(0, shift);
            }
        }
        else
        {
            long double alpha = this->quadratic->getRoot(-1);
            long double betta = this->quadratic->getRoot(1);

            long double f_alpha = this->cubic->getFunctionValue(alpha);
            long double f_betta = this->cubic->getFunctionValue(betta);

            if (std::abs(f_alpha) < this->epsilon && std::abs(f_betta) < this->epsilon)
            {
                this->solutions.push_back((alpha + betta) / 2);
            }
            else if (f_alpha > this->epsilon && f_betta > this->epsilon)
            {
                this->findConcreteSolution(alpha, -1);
            }
            else if (f_alpha < -this->epsilon && f_betta < -this->epsilon)
            {
                this->findConcreteSolution(betta, 1);
            }
            else if (f_alpha > this->epsilon && std::abs(f_betta) < this->epsilon)
            {
                this->solutions.push_back(betta);
                this->findConcreteSolution(alpha, -1);
            }
            else if (std::abs(f_alpha) < this->epsilon && f_betta < -this->epsilon)
            {
                this->solutions.push_back(alpha);
                this->findConcreteSolution(betta, 1);
            }
            else if (f_alpha > this->epsilon && f_betta < -this->epsilon)
            {
                this->borders[0] = alpha;
                this->borders[1] = betta;
                this->solutions.push_back(this->findSolutionInBorders());

                this->findConcreteSolution(alpha, -1);
                this->findConcreteSolution(betta, 1);
            }
        }
    }

    void Executor::printSolutions()
    {
        std::cout << "Solutions" << std::endl;
        for (long double& solution: this->solutions)
        {
            std::cout << solution << std::endl;
        }
    }
}