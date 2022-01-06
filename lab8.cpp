#include <iostream>
#include <cmath>

double input(char key)
{
    std::cout<<key<<": \n";
    double value;
    std::cin >> value;
    return value;
}
void resultOutput(double a,double b,double h)
{
    double x = a;
    while (x <= b)
    {
        double term1 = (1+(x*x))/2 * atan(x);
        double term2 = x/2;
        std::cout<<"Y(x) = " << term1-term2 << "\n";
        x += h;
    }
}

int main() {

    //for Y(X) = (1+x^2)/2 * arctg(x) - x/2
    //в условии сказано можно выбрать любую функцию, поэтому для одной функции n не нужен

    double a = input('a');
    double b = input('b');
    double h = input('h');

    resultOutput(a,b,h);

    return 0;
}
