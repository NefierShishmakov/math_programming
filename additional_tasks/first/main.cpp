#include <iostream>
#include <cmath>

double getFx(double value)
{
    return pow(value, 2) - 5;
}

double getFDerivative(double value)
{
    return 2 * value;
}

double newtonMethod(double x_0)
{
    double prev = x_0;
    double result = 0;

    for (int i = 1; i <= 2; ++i)
    {
        result = prev - getFx(prev) / getFDerivative(prev);
        prev = result;
    }

    return result;
}

double tangentMethod(double x_0)
{
    double prev = x_0;
    double result = 0;

    for (int i = 1; i <= 2; ++i)
    {
        result = prev - getFx(prev) / getFDerivative(x_0);
        prev = result;
    }

    return result;
}

double sekantMethod(double x_0)
{
    double x_1 = x_0 - getFx(x_0) / getFDerivative(x_0);
    double x_2 = x_1 - getFx(x_1) * (x_1 - x_0) / (getFx(x_1) - getFx(x_0));

    return x_2;
}

int main()
{
    double x_0 = 3;

    double newton = newtonMethod(x_0);
    double tangent = tangentMethod(x_0);
    double sekant = sekantMethod(x_0);

    double newton_error = std::abs(newton - sqrt(5));
    double tangent_error = std::abs(tangent - sqrt(5));
    double sekant_error = std::abs(sekant - sqrt(5));

    std::cout << "x2 (newton) - " << newton << std::endl;
    std::cout << "x2 (kasatelnya) - " << tangent << std::endl;
    std::cout << "x2 (sekyshaya) - " << sekant << std::endl;
    std::cout << std::endl;

    std::cout << "Newton error - " << newton_error << std::endl;
    std::cout << "Kasatelnya error - " << tangent_error << std::endl;  
    std::cout << "Sekyshaya error - " << sekant_error << std::endl;

    return 0;
}