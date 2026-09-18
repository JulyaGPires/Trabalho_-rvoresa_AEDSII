#ifndef LEITURA_ARQUIVO_HPP
#define LEITURA_ARQUIVO_HPP
#include <string>
#include <vector>

using namespace std;


vector<string> LerStrings(string nome_arquivo);
vector<int> LerInteiros(string nome_arquivo);
vector<vector<double>> LerPontos(string nome_arquivo);


#endif