
#include <string>
#include <iostream>
using namespace std;

int main(){
  string name = "Wakala";
  string* newname = &name;
  cout<<newname<<endl;
  
  return 0;
};

