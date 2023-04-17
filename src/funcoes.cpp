#include "funcoes.hpp"

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
void processamat(vector<char> elementos, int linha, int coluna, int numero_processo)
{
    char mat[linha][coluna];
    int k = 0;
    ofstream arqmat;
    string aux, nome_arquivo;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            mat[i][j] = elementos[k];
            k++;
        }
    }

    nome_arquivo = "matriz" + to_string(numero_processo) + ".txt";

    arqmat.open(nome_arquivo);

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            aux = mat[i][j];
            arqmat << aux << " ";
        }
        arqmat << endl;
    }

    arqmat.close();
}

void game(int linha, int coluna, int nummat)
{
    nummat = 1;
    int cont = 0, k = 0;
    fstream doc;
    string nome_arq;
    vector<char> elementos;
    char mat[linha][coluna], aux;
    nome_arq = "matriz" + to_string(nummat) + ".txt";

    while(nummat != 3){
    doc.open(nome_arq);
    if (doc.is_open())
    {      
        while (doc >> aux)
        {
            elementos.push_back(aux);
            cont++;
            if (cont == linha * coluna)
            {
                for (int i = 0; i < linha; i++)
                {
                    for (int j = 0; j < coluna; j++)
                    {
                        mat[i][j] = elementos[k];
                        k++;
                    }
                }
                for (int i = 0; i < linha; i++)
                {
                    for (int j = 0; j < coluna; j++)
                    {
                        cout << mat[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }
        doc.close();
    }
    nummat ++;
    nome_arq = "matriz" + to_string(nummat) + ".txt";
    cout << nome_arq << endl;
    }
}
