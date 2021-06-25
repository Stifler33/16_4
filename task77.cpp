#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
enum musik{
    C=1,
    D=2,
    E=4,
    F=8,
    G=16,
    A=32,
    H=64
};
int main(){
    string set = "1142253";

    int melody = 0;
    for (int i = 0; i < set.size(); i++){
        melody += stoi(set,);
        //string c = "";
        //c += set[i];
        //melody += stoi(c);
        //melody += 1<<note;
    }
    cout << melody;
    return 0;
}