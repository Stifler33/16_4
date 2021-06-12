#include <iostream>
#include <sstream>

using namespace std;
int main(){
    double result;
    string number;
    stringstream buffer;
    cin >> number ;
    buffer << number;
    cin >> number;
    buffer << '.' << number;
    cout << buffer.str() << endl;
    //buffer >> result;
    cout << result ;
    return 0;
}