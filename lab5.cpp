#include <iostream>
#include <cmath>

int main() {
    int r;
    std::cout << "Type in amount of rows\n";
    std::cin >> r;

    std::cout << "Type in amount of columns\n";
    int c;
    std::cin >> c;

    int **array = new int *[r];
    int i, j;
    for (i = 0; i < r; i++)
        array[i] = new int[c];
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            std::cout << "Enter element " << "[" << i << "][" << j << "]\n";
            std::cin >> array[i][j];
        }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++) {
            std::cout << array[i][j] << "\t";
        }
        std::cout<<"\n";
    }
    int sum = 0;
    for ( i = 1; i < r; i++)
        for ( j = 0; j < i; j++)
        {

            sum+= std::abs(array[i][j]);
        }
    std::cout<<"Sum = "<<sum<<"\n";

    return 0;
}
