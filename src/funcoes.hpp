#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int gera5();
int gera8();

void processamat(vector<char>elementos, int linha, int coluna, int numero_processo);

void game(int nummat, int linha, int coluna);

void faz(vector<string>elementos, string nome_arq, int linha, int coluna);

