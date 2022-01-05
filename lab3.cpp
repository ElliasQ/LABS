#include <iostream>
#include <cmath>
#include <vector>
void streamCleaner()
{
    std::cin.clear();
    std::cin.ignore();
    std::cout<<"Please enter a valid data\n";
}

double inputValues(char key)
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
        else if(key == 'h' && input <=0)
        {
            std::cout<<"h must be positive"<<"\n";
        }
        else
        {
            valid = true;
        }
    }
    return input;
}

bool checkSanity(double a, double b)
{
    if (a > b)
    {
        std::cout<<"left border is bigger than the right border\nType in values again\n";
        return false;
    }
    return true;
}
void printOutValues(double x, double y, int n)
{
    std::cout<<"N - "<<n<<", x - "<<x<<", y - "<<y<<"\n";
}
int main()
{
    std::string input;

    double a = 1;
    double b = 0;
    while (!checkSanity(a, b))
    {
        a = inputValues('a');
        b = inputValues('b');
    }

    double h = inputValues('h');

    double x = a;
    double y;
    int n = 1;
    double max = 0;
    double min = 0;
    while (x <= b)
    {
        y = x*x*cos(x)*sin(x);
        if (max < y)
        {
            max = y;
        }
        if (min > y)
        {
            min = y;
        }
        printOutValues(x,y,n);
        x += h;
        n++;
    }
    std::cout<<"MAX: " << max << "\n";
    std::cout<<"MIN: " << min << "\n";
    return 0;


}
