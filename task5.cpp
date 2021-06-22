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
float time = 0;
int kelvin = 5000;
string OnOffLHome;
string OnOffLGarden;
string stateTraffic;
int statusTumbler = 0;
bool traffic(string &stateTraffic){
    if (stateTraffic == "yes"){
        return true;
    }else if (stateTraffic == "no") {
        return false;
    }else {
        cerr << "Error traffic ! yes or no\n";
        return false;
    }
}
void shiftLHome(){
    if (OnOffLHome == "on" && !(statusTumbler & LIGHT_HOME)){
        cout << " ON light home ";
        statusTumbler |= LIGHT_HOME;
    }else if (OnOffLHome == "off" && (statusTumbler & LIGHT_HOME)) {
        cout << " OFF light home ";
        statusTumbler &= ~LIGHT_HOME;
    }
}
void statePrint(){
    if (statusTumbler & LIGHT_HOME){
        cout << " On light home ";
        cout << " kelvin " << kelvin;
    }
    if (statusTumbler & LIGHT_GARDEN){
        cout << " On light garden ";
    }
    if (statusTumbler & HEATING){
        cout << " On heating home ";
    }
    if (statusTumbler & HEAT_WATER){
        cout << " On heating water ";
    }
    if (statusTumbler & CONDITIONING){
        cout << " On conditioning ";
    }
    cout << endl;
}
int main(){

    stringstream console;
    string userEnter;
    statusTumbler |= HOUSE;
    statusTumbler |= SOCKETS;
    for (int i = 0; i < 48; i++) {
        getline(cin, userEnter);
        console << userEnter;
        console >> Cout >> Cin >> stateTraffic >> OnOffLHome;

        cout << "Time " << time << ":00" << endl;
        if (Cout < 0 && !(statusTumbler & HEAT_WATER)) {
            cout << "ON heating water ";
            statusTumbler |= HEAT_WATER;
        } else if (Cout > 5 && (statusTumbler & HEAT_WATER)) {
            cout << " OFF heating water ";
            statusTumbler &= ~HEAT_WATER;
        }

        if (time > 16 || time < 5) {
            if (!(statusTumbler & LIGHT_GARDEN) && traffic(stateTraffic)) {
                cout << " ON light garden ";
                statusTumbler |= LIGHT_GARDEN;
            }else if (!traffic(stateTraffic) && (statusTumbler & LIGHT_GARDEN)){
                cout << " OFF light garden ";
                statusTumbler &= ~LIGHT_GARDEN;
            }
        } else if (statusTumbler & LIGHT_GARDEN) {
            cout << " OFF light garden ";
            statusTumbler &= ~LIGHT_GARDEN;
        }

        if (Cin < 22 && !(statusTumbler & HEATING)) {
            cout << " ON Heating ";
            statusTumbler |= HEATING;
        } else if (Cin >= 25 && (statusTumbler & HEATING)) {
            cout << " OFF Heating ";
            statusTumbler &= ~HEATING;
        }
        if (Cin >= 30 && !(statusTumbler & CONDITIONING)) {
            cout << " ON conditioning ";
            statusTumbler |= CONDITIONING;
        } else if (Cin < 25 && (statusTumbler & CONDITIONING)) {
            cout << " OFF conditioning ";
            statusTumbler &= ~CONDITIONING;
        }

        shiftLHome();
        if (statusTumbler & LIGHT_HOME) {
            cout << " kelvin " << kelvin;
        }
        if (time >= 16 && time < 20) {
            kelvin -= 575;
        } else if (time == 0) kelvin = 5000;
        cout << endl;
        //statePrint();
        time ++;
        if (time > 24) {
            time = 0;
        }
        console.clear();
    }
    return 0;
}