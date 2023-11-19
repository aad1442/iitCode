#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define epsilon 10.0e-6
#define f(x) ((x) * (x) * (x) + 4 * (x) * (x) - 10)

int main() {
    int n = 100, i;
    double a1 = -5.0, b1 = 5.0, c, a, b, h;
    
    h = (fabs(a1) + fabs(b1)) / 6;
    a = a1;

    int outerLoopCounter = 0;
    while (outerLoopCounter < 6) {  // Perform 6 iterations in the outer loop
        b = a + h;
        if (f(a) * f(b) > 0) {
            printf("   i     a      b       c      f(a)       f(b)       f(c)\n");
            printf("%3d %0.5lf %0.5lf %.5lf %.5lf %.5lf %.5lf\n ", outerLoopCounter, a, b, c, f(a), f(b), f(c));
            printf("no root\n");
        }
        else {
            printf("   i     a     b     c     f(a)     f(b)     f(c)\n");
            for (i = 0; i < n; i++) {
                c = (a + b) / 2;
                if (fabs(f(c)) < epsilon) {
                    printf("Root : %lf\n", c);
                    break;  // Exit the inner loop once a root is found
                }
                printf("%3d %0.5lf %0.5lf %.5lf %.5lf %.5lf %.5lf\n ", i, a, b, c, f(a), f(b), f(c));
                if (f(a) * f(c) < 0)
                    b = c;
                else
                    a = c;
            }
        }
        a = b;
        outerLoopCounter++;  // Increment the counter for the outer loop
    }
    return 0;
}
