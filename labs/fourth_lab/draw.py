import matplotlib.pyplot as plt
import numpy as np
import constants


def draw(u_approximate_solution: np.ndarray, u_exact_solution: np.ndarray) -> None:
    x_values_approximate = np.linspace(constants.LEFT_X_EDGE, constants.RIGHT_X_EDGE, u_approximate_solution.shape[0])
    x_values = np.linspace(constants.LEFT_X_EDGE, constants.RIGHT_X_EDGE, u_exact_solution.shape[0])

    plt.plot(x_values_approximate, u_approximate_solution)
    plt.plot(x_values, u_exact_solution)

    plt.show()


