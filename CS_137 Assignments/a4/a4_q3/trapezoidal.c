#include<stdio.h>
#include<assert.h>
#include<math.h>
#define PI acos(-1)

double trapArea(double (*f) (double), double a, double b){
    return (0.5 * (b-a) * (f(a)+f(b)));
}

double graphArea(double (*f) (double), double a, double b, int n){
    double split = (b-a)/n;
    double initial = a;
    double final = initial + split;
    double sum = 0.0;
    while (initial < b){
        sum += trapArea(*f, initial, final);
        final += split;
        initial += split;
    }
    return sum;

}

double trapezoidal(double (*f) (double), double a, double b, double epsilon, int n){
    double temp = graphArea(*f, a, b, n);
    if (fabs(graphArea(*f, a, b, 2*n) - temp) <= epsilon) return temp;
    return trapezoidal(*f, a, b, epsilon, 2*n);
}
