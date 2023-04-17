#include "funcoes.hpp"
using namespace std;

int main(){
    
    int linha, coluna, nummat;
    ifstream input;
    vector<char>elementos;
    char aux;
    int cont;
    int numero_processo = 1;

    input.open("./dataset/input.data");
    if(input.is_open()){
        input >> linha >> coluna >> nummat;
        while(input >> aux){
            elementos.push_back(aux);
            cont ++;
            if(cont == linha*coluna){
                processamat(elementos, linha, coluna, numero_processo);
                cout << endl << endl << endl;
                cont=0;
                elementos.clear();
                numero_processo++;
            }
        }
        input.close();
    }
    game(linha, coluna, nummat);

    return 0;
}