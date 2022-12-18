import matplotlib.pyplot as plt
import numpy as np
from constants import *


def draw(u_approximate_solution: np.ndarray, u_exact_solution: np.ndarray, intervals_num: int,
         r: float, a: float) -> None:
    plt.title("The solution of diff equation: du / dt + a * du / dx = 0")
    plt.ylabel("Time dimension")
    plt.xlabel("Spatial dimension")

    x_values = np.linspace(LEFT_X_EDGE, RIGHT_X_EDGE, u_approximate_solution.shape[1])

    approximate_solution_t_1 = u_approximate_solution[-1]
    exact_solution_t_1 = u_exact_solution[-1]

    plt.plot(x_values, approximate_solution_t_1)
    plt.plot(x_values, exact_solution_t_1)

    plt.show()
