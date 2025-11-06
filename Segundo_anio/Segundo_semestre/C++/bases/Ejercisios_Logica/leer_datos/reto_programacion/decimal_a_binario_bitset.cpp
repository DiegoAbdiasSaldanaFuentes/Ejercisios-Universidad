#include <iostream>
#include <bitset>

int main(){
    std::string s = std::bitset<64>(1).to_string(); //conversion de string
    std::cout << std::bitset < 64 >(9) << ' '; 

    std::bitset< 64 > input;
    std::cin >> input;
    unsigned long ult = input.to_ulong();
    return 0;
}