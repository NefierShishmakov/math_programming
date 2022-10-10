#include "executor.hpp"

// epsilon = 0.0000001 delta = 5
int main()
{
    long double epsilon, delta, a, b, c;

    std::cin >> epsilon >> delta >> a >> b >> c;

    ExecutorSpace::Executor executor(epsilon, delta, a, b, c);

    executor.findSolutions();

    std::cout << std::endl;
    executor.printSolutions();

    return 0;
}
