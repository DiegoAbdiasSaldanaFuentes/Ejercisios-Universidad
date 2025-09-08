#include <iostream>
#include <string>

using namespace std;

string LCS(string X, string Y){
    string resultado = "";

    for(int i = 0; i< X.length(); i++){
        for(int len = 0; len<= X.length() -i;len++){
            string sub = X.substr(i,len);

            if(Y.find(sub) != string::npos && sub.length()>resultado.length()){
                resultado = sub;
            }
        }
    }
    return resultado;

}

int main(){
    string X = "ABBC";
    string Y = "BABC";
    
    cout<<"Resultado: "<<LCS(X,Y)<<endl;
}