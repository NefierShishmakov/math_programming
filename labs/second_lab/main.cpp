#include <iostream>
#include <vector>
#include <cmath>

#define SIZE 2
#define TRAPEZOIDAL 0
#define SIMPSON 1

double get_function_value(const double x, bool isAdditional)
{
    return (isAdditional ? sin(x) : exp(x));
}

double get_intermediate_result(const double first, const double second, const int method, bool isAdditional)
{
    double res = 0;

    switch (method)
    {
        case TRAPEZOIDAL:
            res = (second - first) * (get_function_value(first, isAdditional) + get_function_value(second, isAdditional)) / 2.0;
            break;
        case SIMPSON:
            res = ((second - first) / 6.0) * (get_function_value(first, isAdditional) + 4.0 *
            get_function_value((first + second) / 2, isAdditional) + get_function_value(second, isAdditional));
            break;
    }

    return res;
}

void fill_dots(std::vector<double>& dots, const double a, const double b, const int intervals_num)
{
    double interval_length = (b - a) / intervals_num;

    double start = a;

    for (int i = 0; i < intervals_num; ++i)
    {
        dots.push_back(start);
        start += interval_length;
    }

    dots.push_back(b);
}

void get_integrals_values(double *const results, const double a, const double b, const int intervals_num)
{
    std::vector<double> dots;
    fill_dots(dots, a, b, intervals_num);

    for (int i = 0; i < intervals_num; ++i)
    {
        results[0] += get_intermediate_result(dots[i], dots[i + 1], TRAPEZOIDAL, false);
        results[1] += get_intermediate_result(dots[i], dots[i + 1], SIMPSON, false);
    }
}

void print_results(double *const results)
{
    std::cout << "The trapezoidal method integral value: " << results[TRAPEZOIDAL] << std::endl;
    std::cout << "The simpson method integral value: " << results[SIMPSON] << std::endl;
}

double get_results_s(std::vector<double>& dots, const int intervals_num, const int method)
{
    double result = 0.0;

    for (int i = 0; i < intervals_num; ++i)
    {
        result += get_intermediate_result(dots[i], dots[i + 1], method, true);
    }

    return result;
}

void set_additional_results(double *additional_results, double a, double b, const int first_intervals_num,
                            const int second_intervals_num, const int method)
{
    std::vector<double> dots_s_h;
    std::vector<double> dots_s_h2;

    fill_dots(dots_s_h, a, b, first_intervals_num);
    fill_dots(dots_s_h2, a, b, first_intervals_num * 2);

    double first_result_s_h = get_results_s(dots_s_h, first_intervals_num, method);
    double first_result_s_h2 = get_results_s(dots_s_h2, 2 * first_intervals_num, method);

    dots_s_h.clear();
    dots_s_h2.clear();

    fill_dots(dots_s_h, a, b, second_intervals_num);
    fill_dots(dots_s_h2, a, b, second_intervals_num * 2);

    double second_result_s_h = get_results_s(dots_s_h, second_intervals_num, method);
    double second_result_s_h2 = get_results_s(dots_s_h2, 2 * second_intervals_num, method);

    additional_results[0] = log2((first_result_s_h - 1) / (first_result_s_h2 - 1));
    additional_results[1] = log2((second_result_s_h - 1) / (second_result_s_h2 - 1));
}

void get_results_of_additional_task(double ( *additional_results)[SIZE], const int first_intervals_num,
                                    const int second_intervals_num)
{
    double a = 0.0;
    double b = std::numbers::pi / 2.0;

    set_additional_results(additional_results[TRAPEZOIDAL], a, b, first_intervals_num, second_intervals_num, TRAPEZOIDAL);
    set_additional_results(additional_results[SIMPSON], a, b, first_intervals_num, second_intervals_num, SIMPSON);
}

void print_additional_results(double ( *additional_results)[SIZE])
{
    std::cout << "Trapezoidal method (h = (pi / 200)): " << additional_results[TRAPEZOIDAL][0] << std::endl;
    std::cout << "Trapezoidal method (h = (pi / 400)): " << additional_results[TRAPEZOIDAL][1] << std::endl;
    std::cout << std::endl;

    std::cout << "Simpson method (h = (pi / 200)): " << additional_results[SIMPSON][0] << std::endl;
    std::cout << "Simpson method (h = (pi / 400)): " << additional_results[SIMPSON][1] << std::endl;
}

int main()
{
    // Численное значение интеграла методом трапеций и симпсона
    /*double results[SIZE] = {0, 0};
    double a;
    double b;
    int intervals_num;

    std::cout << "Enter borders: ";
    std::cin >> a >> b;

    std::cout << "Enter intervals number: ";
    std::cin >> intervals_num;


    get_integrals_values(results, a, b, intervals_num);

    print_results(results);
    std::cout << std::endl;*/


    // Методом трапеций и симпсона подсчитать log2((S_h - I) / (S_(h/2) - I)), где I = интеграл от sinx, от 0 до pi / 2
    /*double additional_results[SIZE][SIZE] = {{0, 0}, {0, 0}};

    get_results_of_additional_task(additional_results, 100, 200);
    print_additional_results(additional_results);*/

    return 0;
}
