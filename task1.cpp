#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;
float speed = 0;
bool permissibleSpeed(float delta){
   return speed <= 0 - delta;
}
int main() {
    float delta;
    char text[100];
    do{
        cin >> delta;
        if (delta + speed <= 150) {
            speed += delta;
            sprintf(text, "Speed %.2f", speed);
            cout << text << endl;
        }else cout << "over speed !\n";
    }while(!permissibleSpeed(0.01));
    return 0;
}
