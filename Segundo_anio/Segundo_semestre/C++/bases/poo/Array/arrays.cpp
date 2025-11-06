#include <iostream>
#include <string>

class Strings{

    private:
        std::string X;
        std::string Y;
    
    public:
        void setAtributos(std::string str1, std::string str2){
            X = str1;
            Y = str2;
        }

        std::string getString1(){
            return X;
        }

        std::string getString2(){
            return Y;
        }

        void LSC(){
            for(int i = 0; i< X.length(); i++){
                for(int j= 0; j<Y.length(); j++){
                    if(X[i]==Y[j]){
                        std::cout<<"Coincide:"<<"X="<<X[i]<<"Y="<<Y[j]<<std::endl;
                    }else{
                        std::cout<<"No coincide"<<std::endl;
                    }

                }
            }
        }

        void Substrin(){
            std::cout<<X.substr(0,2)<<std::endl;
            std::cout<<X.substr(2,3)<<std::endl;
            std::cout<<X.substr(5,7)<<std::endl;
        }

        void matriz(){
            int fila= X.length(), columna=Y.length();
            int matris[3][4];

            for(int i= 0; i <fila; i++){
                for(int j= 0; j<columna; j++){
                    matris[i][j]= 1;
                }
            }
            
            for(int i= 0; i <fila; i++){
                for(int j= 0; j<columna; j++){
                    std::cout<<matris[i][j];
                }
            }std::cout<<std::endl;
        }
};

int main(){

    Strings string1;
    string1.setAtributos("hola","chatyipiti");
    //string1.LSC();
    //string1.Substrin();
    string1.matriz();
    return 0;
}

