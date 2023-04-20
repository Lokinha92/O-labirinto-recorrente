#include "funcoes.hpp"

int gera5()
{
    unsigned seed = time(0);
    int num;

    srand(seed);
    num = 1 + rand() % 5;

    return num;
}

int gera8()
{
    unsigned seed = time(0);
    int num;

    srand(seed);
    num = 1 + rand() % 8;

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

void game(int nummat, int linha, int coluna)
{
    int numarq = 1;
    string nome_arq;
    vector<string> elementos;
    fstream doc;
    string mat[linha][coluna], aux;
    int cont = 0, k = 0;
    //int i_atual = 1, j_atual = 0;
    int vidas = 10; // bussola = 0, banco = 0;
    
    cout << nummat << endl << endl;

    while (vidas > 0)
    {
        //while (numarq <= nummat)
        //{
            nome_arq = "matriz" + to_string(numarq) + ".txt";
            doc.open(nome_arq);
            if (doc.is_open())
            {
                while (getline(doc, aux, ' '))
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
                        cont = 0;
                        elementos.clear();
                    }
                }
                doc.close();
            }

            for (int i = 0; i < linha; i++)
            {
                for (int j = 0; j < coluna; j++)
                {
                    cout << mat[i][j] << " ";
                }
                //cout << endl;
            }

            vidas = 0;

            // while ((i_atual != 0 && j_atual != 0) || (i_atual != linha - 1 && j_atual != coluna - 1))
            // {
            //     if (i_atual != 0 && j_atual == 0)
            //     {

            //         bussola = 1;
            //         if (bussola == 1)
            //         {
            //             i_atual--;
            //             cout << "aqui" << endl;
            //             cout << "vidas ---> " << vidas << endl;
            //             vidas ++;
            //             cout << "vidas ---> " << vidas << endl;                        
            //             if (mat[i_atual][j_atual] == "*")
            //             {
            //                 vidas--;
            //             }
            //             else if (mat[i_atual][j_atual] == "#")
            //             {
            //                 i_atual++;
            //             }
            //             else if (mat[i_atual][j_atual] == "1" || mat[i_atual][j_atual] == "2" || mat[i_atual][j_atual] == "3" || mat[i_atual][j_atual] == "4" || mat[i_atual][j_atual] == "5")
            //             {
            //                 mat[i_atual][j_atual] = stoi(mat[i_atual][j_atual]) - 1;
            //                 banco++;
            //                 vidas = 0;
            //             }
            //         }
            //     }
            // }
        //}
    }
    cout << "FIM DE JOGO! AS VIDAS CHEGARAM A 0" << endl << endl;
}