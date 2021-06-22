#include <iostream>
using namespace std;
enum swith {
    HOME = 1,
    SOCKETS=2,
    CONDITIONING=4,
    HEATING=8
};
void printStatus(int& status){
    if (status & HOME){
        cout << " Home ON " ;
    }
    if (status & SOCKETS){
        cout << " Sockets ON " ;
    }
    if (status & CONDITIONING){
        cout << " CONDITIONING ON " ;
    }
    if (status & HEATING){
        cout << " HEATING ON " ;
    }
    cout << endl;
}
int main(){
    int status = 0;
    status |= HOME;
    //status |= HEATING;
    printStatus(status);
    status &= ~HOME;
    if (!(status & HEATING)){
        cout << "yes !!";
    }
    printStatus(status);
    status &= ~HEATING;
    if (!(status & HEATING)){
        cout << "yes !!";
    }
    return 0;
}