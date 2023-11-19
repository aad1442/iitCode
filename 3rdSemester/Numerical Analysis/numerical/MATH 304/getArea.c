#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define epsilon 10.0e-6
#define f(x) ((x) * (x))
#define g(x) (pow(x,0.5))
#define h(x) (g(x) - f(x))

double a, b, c, sumX, sumO, sumE;

void simpson_rule(int n, double a, double b) {
    if ((n % 2) != 0) {
        n = n + 1;
    }
    double h = (b - a) / n;
    double x[11], y[11];
    x[0] = a;
    x[n] = b;
    for (int i = 1; i < n; i++) {
        x[i] = x[i - 1] + h;
    }
    for (int i = 0; i <= n; i++) {
        y[i] = h(x[i]);
    }
    sumX = y[0] + y[n];
    for (int i = 1; i < n; i++) {
        if ((i % 2) == 0)
            sumE += y[i];
        else
            sumO += y[i];
    }
    printf("sumX %lf sumO %lf sumE %lf\n", sumX, sumO, sumE);
    printf("\"x\" \t\t\"f(x)\"\n");
    for (int i = 0; i <= n; i++) {
        printf("%lf\t %lf\n", x[i], y[i]);
    }
    printf("Integral value: %lf\n", h * (sumX + (4 * sumO) + (2 * sumE)) / 3);
}

double getRoot(int n) {
    int i;
    if (h(a) * h(b) > 0) {
        printf("no root\n");
        return -1; // Indicate no root found
    }
    for (i = 0; i < n; i++) {
        c = (a + b) / 2;

        if (fabs(h(c)) < epsilon) {
            return c;
        }
        if (h(a) * h(c) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

int main() {
    a = 0.0;
    b = 2.0;
    int n = 10;

    double root = getRoot(n);
    printf("Root: %lf",root);
    if (root != -1) {
        simpson_rule(n, a, root);
    }
    return 0;
}
