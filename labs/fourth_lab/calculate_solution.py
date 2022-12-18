import constants
import numpy as np


def y(x: float) -> float:
    return -(x ** 2) + x


def calc_exact_solution(x_nodes_number: int) -> np.ndarray:
    h = (constants.RIGHT_X_EDGE - constants.LEFT_X_EDGE) / (x_nodes_number - 1)
    y_sol = np.zeros([x_nodes_number], dtype=float)

    for i in range(1, x_nodes_number - 1):
        y_sol[i] = y(i * h)

    return y_sol


def calc_approximate_solution(x_nodes_number: int) -> np.ndarray:
    h = (constants.RIGHT_X_EDGE - constants.LEFT_X_EDGE) / (x_nodes_number - 1)
    f = -2.0
    c = (-2.0) / (h ** 2)
    b = (-1.0) / (h ** 2)
    a = (-1.0) / (h ** 2)

    y_sol = np.zeros([x_nodes_number], dtype=float)

    alpha_values = np.zeros([x_nodes_number - 3], dtype=float)
    betta_values = np.zeros([x_nodes_number - 3], dtype=float)

    # first step: calculating alpha and betta coefficients
    alpha_values[0] = b / c
    betta_values[0] = f / c

    for i in range(1, x_nodes_number - 3):
        alpha_values[i] = b / (c - a * alpha_values[i - 1])
        betta_values[i] = (f + a * betta_values[i - 1]) / (c - a * alpha_values[i - 1])
    ######################################################

    # second step: calculating y values
    y_sol[x_nodes_number - 2] = (f + betta_values[x_nodes_number - 4] * a) / (c - alpha_values[x_nodes_number - 4] * a)

    for i in range(x_nodes_number - 3, 0, -1):
        y_sol[i] = alpha_values[i - 1] * y_sol[i + 1] + betta_values[i - 1]
    ####################################

    return y_sol
