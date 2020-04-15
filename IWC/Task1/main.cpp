#include <iostream>
#include <cmath>

double f1(double x) {
    return (-2 * x * x + 3) / 8;
}

double f2(double x) {
    return -1 * std::sqrt((3 - 8 * x) / 2);
}

double g(double x) {
    return 2 * x * x + 8 * x - 3;
}

int main() {
    double accuracy = 0.0001;
    double x = 0;
    int num_iterations = 0;

    while (std::abs(f1(x) - x) > accuracy) {
        x = f1(x);

        num_iterations++;
    }

    std::cout << "Number of iterations: " << num_iterations << std::endl << "Solution: " << x << std::endl << "Value: " << g(x) << std::endl << std::endl;

    x = -4;
    num_iterations = 0;

    while (std::abs(f2(x) - x) > accuracy) {
        x = f2(x);

        num_iterations++;
    }

    std::cout << "Number of iterations: " << num_iterations << std::endl << "Solution: " << x << std::endl << "Value: " << g(x);

    return 0;
}
