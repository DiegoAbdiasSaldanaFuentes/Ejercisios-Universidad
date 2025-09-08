#include <iostream>
#include <string>
using namespace std;

int main(){

    string X = "ABC";
    string Y = "BABA";

    cout << "X[0]: "<< X[0]<< endl; //'A'
    cout << "Y[1]: "<< Y[0]<< endl; //'A'

    if (X[0] == Y[1]){
        cout << "Son iguales"<<endl;
    }else{
        cout<< "Son distintos"<<endl;
    }
    return 0;
}