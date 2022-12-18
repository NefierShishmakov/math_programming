import calculate_solution as cs
import constants
import draw as dr
from itertools import product


def main() -> None:
    x_nodes_numbers = [11, 101, 1001]

    for combination_values in product(x_nodes_numbers):
        x_nodes_number = combination_values[0]

        print("Make computing with values: x_nodes_number - {}".format(x_nodes_number), end='\n')

        print("Computing approximate solution", end='\n')
        u_approximate_solution = cs.calc_approximate_solution(x_nodes_number)
        print("Done computing approximate solution", end='\n')

        print("Computing exact solution", end='\n')
        u_exact_solution = cs.calc_exact_solution(constants.DOTS_NUM_FOR_EXACT_SOLUTION)
        print("Done computing exact solution", end='\n')

        print("Making graphs", end='\n')
        dr.draw(u_approximate_solution, u_exact_solution)
        print("Done making graphs", end='\n')


main()
