#include "funcoes.hpp"

void exemplo(string nome_arquivo) {
    fstream myfile;
    myfile.open(nome_arquivo);
    string aux;
    int cont;

    cout << "NOME DO ARQUIVO: " << nome_arquivo << endl << endl;
    
    if (myfile.is_open()) {
        while (getline (myfile, aux, ' ')) {
            cout << aux << " ";

            if (cont == 7) {
                cout << endl;
                cont = 0;
            }
        }
    }
}

int gerar()
{
    unsigned seed = time(0);
    int num;

    srand(seed);
    num = 1 + rand() % 3;

    return num;
}

/// @brief
/// @param elementos
/// @param linha
/// @param coluna
/// @param nummat
void game(vector<char> elementos, int linha, int coluna, int nummat, int numero_processo)
{
    char mat[linha][coluna];
    int k = 0;
    ofstream arqmat;
    string aux, nome_arquivo;

    cout << "Numero de matrizes: " << nummat << endl;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            mat[i][j] = elementos[k];
            k++;
        }
    }

    nome_arquivo = "matriz" + to_string(numero_processo) + ".txt";
    // cout << nome_arquivo << endl;
    arqmat.open(nome_arquivo);

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            // if (arqmat.is_open())
            // {
            //     arqmat << mat[i][j] << " "; 
            // }
            // arqmat << "a ";
            aux = mat[i][j];
            arqmat << aux << " ";
        }
        arqmat << endl;
    }

    arqmat.close();
    exemplo(nome_arquivo);
}

