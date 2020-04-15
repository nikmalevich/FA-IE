#include <iostream>
#include <iomanip>

void func(const double* vector, double* new_vector) {
    new_vector[0] = (4 * vector[1] + 3 * vector[2] - 2 * vector[3] + 29) / 20;
    new_vector[1] = (vector[0] - vector[2] + vector[3] + 8) / 5;
    new_vector[2] = (-3 * vector[0] - 3 * vector[1] + vector[3] + 29) / 8;
    new_vector[3] = (3 * vector[0] - 2 * vector[1] + vector[2] + 38) / 10;
}

double norm(double* v1, double* v2) {
    double max = std::abs(v1[0] - v2[0]);

    for (int i = 1; i < 4; i++) {
        double dist = std::abs(v1[i] - v2[i]);

        if (max < dist) {
            max = dist;
        }
    }

    return max;
}

int main() {
    double accuracy = 0.001;
    auto* vector = new double[4]();
    auto* new_vector = new double[4]();
    int num_iterations = 0;

    do {
        std::swap(vector, new_vector);

        func(vector, new_vector);

        num_iterations++;
    } while (norm(new_vector, vector) > accuracy);

    std::cout << "Number of iterations: " << num_iterations << std::endl << "Solution: " ;

    for (int i = 0; i < 4; i++) {
        std::cout << std::fixed << std::setprecision(4) << new_vector[i] << ' ';
    }

    return 0;
}
