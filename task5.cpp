#include <iostream>
#include <sstream>
using namespace std;
enum tumbler{
    HOUSE = 1,
    SOCKETS,
    LIGHT_HOME = 4,
    LIGHT_GARDEN = 8,
    HEATING = 16,
    HEAT_WATER = 32,
    CONDITIONING = 64
};
float Cout;
float Cin;
float time;
bool traffic;
int kelvin;
int main(){
    int statusTumbler = 0;

    if (Cout < 0){
        statusTumbler |= HEAT_WATER;
    }else if (Cout > 5) statusTumbler &= ~HEAT_WATER;

    if (time > 16 && time < 5 && traffic){
        statusTumbler |= LIGHT_GARDEN;
    }else statusTumbler &= ~LIGHT_GARDEN;

    if (Cin < 22){
        statusTumbler |= HEATING;
    }else if (Cin >= 25) statusTumbler &= ~HEATING;

    if (Cin > 30){
        statusTumbler |= CONDITIONING;
    }else if (Cin < 25) statusTumbler &= ~CONDITIONING;

    if (time > 16 && (statusTumbler & LIGHT_HOME)){
        kelvin -= (time - 16) * 575;
    }else if (time == 0) kelvin = 5000;
    return 0;
}