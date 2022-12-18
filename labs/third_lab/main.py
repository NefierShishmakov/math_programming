import calculate_solution as cs
import draw as dr
from itertools import product


def main() -> None:
    x_nodes_numbers = [101, 1001]
    r_values = [0.25, 0.5, 1.0, 1.25]
    a_values = [1.0]

    for combination_values in product(x_nodes_numbers, r_values, a_values):
        x_nodes_number = combination_values[0]
        r = combination_values[1]
        a = combination_values[2]

        print("Make computing with values: x_nodes_number - {}, r - {}, a - {}".format(x_nodes_number, r, a), end='\n')

        print("Computing approximate solution", end='\n')
        u_approximate_solution = cs.calc_approximate_solution(x_nodes_number, r, a)
        print("Done computing approximate solution", end='\n')

        print("Computing exact solution", end='\n')
        u_exact_solution = cs.calc_exact_solution(x_nodes_number, r, a)
        print("Done computing exact solution", end='\n')

        print("Making graphs", end='\n')
        dr.draw(u_approximate_solution, u_exact_solution, x_nodes_number - 1, r, a)
        print("Done making graphs", end='\n')


main()
