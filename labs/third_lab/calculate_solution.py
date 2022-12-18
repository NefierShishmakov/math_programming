import numpy as np
from math import ceil
from constants import *


def v(arg: float) -> float:
    if arg <= 0.0:
        return 3.0
    return 1.0


def u(x: float, a: float, t: float) -> float:
    return v(x - a * t)


def calc_approximate_solution(x_nodes_number: int, r: float, a: float) -> np.ndarray:
    h = (RIGHT_X_EDGE - LEFT_X_EDGE) / (x_nodes_number - 1)
    tau = r * h / a
    t_nodes_number = ceil((TOP_T_EDGE - BOTTOM_T_EDGE) / tau) + 1

    grid = np.zeros([t_nodes_number, x_nodes_number], dtype=float)

    for xi in range(x_nodes_number):
        grid[0][xi] = v(xi * h + LEFT_X_EDGE)

    for ti in range(1, t_nodes_number, 1):
        grid[ti][0] = 3.0
        for xi in range(1, x_nodes_number, 1):
            grid[ti][xi] = grid[ti - 1][xi] * (1.0 - r) + grid[ti - 1][xi - 1] * r

    return grid


def calc_exact_solution(x_nodes_number: int, r: float, a: float) -> np.ndarray:
    h = (RIGHT_X_EDGE - LEFT_X_EDGE) / (x_nodes_number - 1)
    tau = r * h / a
    t_nodes_number = ceil((TOP_T_EDGE - BOTTOM_T_EDGE) / tau) + 1

    grid = np.zeros([t_nodes_number, x_nodes_number], dtype=float)

    for ti in range(t_nodes_number):
        for xi in range(x_nodes_number):
            grid[ti][xi] = u(LEFT_X_EDGE + xi * h, a, BOTTOM_T_EDGE + ti * tau)

    return grid
