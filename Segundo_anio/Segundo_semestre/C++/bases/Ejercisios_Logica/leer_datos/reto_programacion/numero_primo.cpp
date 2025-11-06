#include <iostream>

int main(){
    int num = 25;
    
    if(num / num == 1 && num % 2 == 1 && num * num %3 == 1){
	    std::cout<<"TU NUMERO ES PRIMO";
    }
    else{
	    std::cout<<"TU NUMERO NO ES PRIMO";
    }
    return 0;
}