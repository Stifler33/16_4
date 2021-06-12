#include <iostream>
#include <sstream>

int main(){
    std::string userAns;
    std::cin >> userAns;
    std::stringstream buffer;
    buffer << userAns;
    double first;
    double second;
    char sing;
    buffer >> first >> sing >> second;
    //std::cout << first << " " << sing << " " << second << std::endl;
    switch (sing) {
        case'+':
            std::cout << first + second;
            break;
        case'-':
            std::cout << first - second;
            break;
        case'*':
            std::cout << first * second;
            break;
        case'/':
            std::cout << first / second;
            break;
        default :
            std::cout << "Fail!\n";
    }
    return 0;
}