#include <iostream>
#include <string>
#include <math.h>
#include <cmath>

void streamCleaner()
{
    std::cin.clear();
    std::cin.ignore();
    std::cout<<"Please enter a valid data\n";
}
void checkDomainOfTan(double value)
{
    if (abs(tan(value*1/2)) == NAN)
    {
        std::cout<<"tan (x/2) is undefined";
        exit(1);
    }
}
bool checkDivisionByZero(double x, double y)
{
    const double epsilon = 0.00003;
    return std::abs(x - y) <= epsilon * std::abs(x);
}

double inputParameterValue(char key)
{
    bool valid = false;
    double input;

    while(!valid)
    {

        std::cout << "Input a value of " << key << "\n";
        std::cin >> input;

        if (std::cin.fail())
        {
            streamCleaner();
        }
        else if(key == 'z')
        {
            if(!checkDivisionByZero(0.0,input))
            {

                valid = true;
            }
            else
            {
                std::cout<<key<<"can't be equal zero, because cos(x) is in the denominator will be equal zero and ln(0) is undefined\n";
            }

        }
        else
        {
            valid = true;
        }
    }

    return input;
}

double calculateX(double z)
{
    double result;
    if (z > 0)
    {
        result = sqrt(z);
        checkDomainOfTan(result);
        std::cout<<"z > 0, therefore x = z^1/2\n";
    }
    else
    {
        result = z*z*z;
        checkDomainOfTan(result);
        std::cout<<"z <= 0, therefore x = z^2 / 2\n";
    }
    return result;
}

int pickFunction()
{
    std::string input;
    std::cout<<"Pick a function(Enter a digit from 1 to 3):\n1 - 2x\n2 - x^2\n3 - x/3\n";
    bool valid = false;
    while(!valid)
    {
        std::cin >> input;
        if(std::isdigit(input[0]) && (input[0] == '1' || input[0] == '2' || input[0] == '3'))
        {
            valid = true;
        }
        else
        {
            streamCleaner();
        }
    }
    return input[0];
}

double Calculate_function_value(int choice, double x)
{
    switch(choice)
        {
            case 1:
                return  2*x;
            case 2:
                return x*x;
            case 3:
                return  x/3;
        }
    return 0;
}

int main()
{
    std::string input;

    double z = inputParameterValue('z');

    double x = calculateX(z);



    int choice = pickFunction();

    double function_value = Calculate_function_value(choice, x);

    double a = inputParameterValue('a');
    double b = inputParameterValue('b');

    double term1 = (b*function_value)/cos(x);
    double term2 = a*log(tan(x/2));

    double y = term1 + term2;

    std::cout << "y = " << y << "\n";

    return 0;


}
