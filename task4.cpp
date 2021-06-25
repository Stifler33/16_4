#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
enum note{
    C=1,
    D=2,
    E=4,
    F=8,
    G=16,
    A=32,
    H=64
};
int main(){
    std::string melody;

    for(int i = 0; i < 3; i++){
        std::string user;
        std::cin >> user;
        melody += user;
        if (i < 2) melody += " ";
    }
    std::cout << melody;
    return 0;
}
