#include <iostream>

int main()
{
    int n = 0;

    do {
        std::cout<<"Type in number of elements: "<<"\n";
        std::cin >> n;
    }while(n<=0);

    int array[n];
    int target_index = -1;
    for(int i = 0; i < n;i++)
    {
        std::cout<<"Type in element number "<<i+1<<"\n";
        std::cin>>array[i];
        if(array[i] == 0)
        {
            target_index = i;
        }
    }
    int sum=0;
    if(target_index != -1 &&target_index != n)
    {
        for(int i = target_index + 1; i < n;i++)
        {
            sum+=array[i];
        }
    }
    std::cout<<"sum is equal "<<sum<<"\n";
    return 0;
}
