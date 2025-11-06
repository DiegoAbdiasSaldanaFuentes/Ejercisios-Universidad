#include <iostream>
#include <cstring> // para memeset
using namespace std;

int main(){
    int arr[5][5];
    memset(arr, -1, sizeof(arr)); // pone  todo en 0

    //mostrar
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout<< arr[i][j]<<" ";

        }
        cout << endl;
    }
    return 0;
}