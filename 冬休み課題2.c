#include <stdio.h>

#define steps 10

double f(double x, double y, double z);
double g(double x, double y, double z);

void rungeKutta(double x0, double y0, double z0, double h);

int main() {
    double x0, y0, z0,h;

    printf("Enter x0 : "); scanf("%lf",&x0);
    printf("Enter y0 : "); scanf("%lf",&y0);
    printf("Enter z0 : "); scanf("%lf",&z0);
    printf("Enter h : "); scanf("%lf",&h);
    puts("");

    rungeKutta(x0, y0, z0, h);

    return 0;
}

double f(double x, double y, double z) {
    return (-y/5+z/20); 
}

double g(double x, double y, double z) {
    return (y/5-z/5); 
}

void rungeKutta(double x0, double y0, double z0, double h) {
    double x = x0, y = y0, z = z0;

    printf("x = %.2f, y = %.6f, z = %.6f\n", x, y, z);

    for (int i = 1; i <= steps; ++i) {
        double k1y = h * f(x, y, z);
        double k1z = h * g(x, y, z);

        double k2y = h * f(x + 0.5 * h, y + 0.5 * k1y, z + 0.5 * k1z);
        double k2z = h * g(x + 0.5 * h, y + 0.5 * k1y, z + 0.5 * k1z);

        double k3y = h * f(x + 0.5 * h, y + 0.5 * k2y, z + 0.5 * k2z);
        double k3z = h * g(x + 0.5 * h, y + 0.5 * k2y, z + 0.5 * k2z);

        double k4y = h * f(x + h, y + k3y, z + k3z);
        double k4z = h * g(x + h, y + k3y, z + k3z);

        y = y + (k1y + 2 * k2y + 2 * k3y + k4y) / 6.0;
        z = z + (k1z + 2 * k2z + 2 * k3z + k4z) / 6.0;
        x = x0 + i * h;

        printf("x = %.2f, y = %.6f, z = %.6f\n", x, y, z);
    }
}