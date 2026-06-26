#include <iostream>
#include <string>


int main(){

    for(int i=0; i<=100; i++){
        for(int j=128; j>=0; j--){
            char letra = j;
            std::cout<<letra<<std::endl;
        };
        
    };

    return 0;
}