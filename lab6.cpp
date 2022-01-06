#include <iostream>
#include <string>

int main() {
    std::cout<<"Enter a string\n";

    std::string input;

    std::getline(std::cin,input);


    std::string letter = "$";

    int index = 0;

    while((index = input.find(" ", index)) != std::string::npos) {
        input.replace(index, letter.length(), letter);
        index += letter.length();
    }

    std::cout<<"new string : " << input<<"\n";

    return 0;
}
