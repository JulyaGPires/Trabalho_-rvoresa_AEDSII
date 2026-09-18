#include "Leitura_Arquivo.hpp"
#include "Testes.hpp"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){

  ofstream saida("output/resultados.csv");

  saida << "estrutura,tipo,n,insercao_ms,busca_ms,"
        << "remocao_ms,nns_ms,range_ms" << endl;

  vector<int> tamanhos = {100, 1000, 10000, 50000, 100000};
  vector<string> tipos_strings = {"aleatorio", "ordenado", "decrescente"};

  for(string tipo : tipos_strings){

    string nome_arquivo = "data/strings_" + tipo + ".csv";
    vector<string> dados = LerStrings(nome_arquivo);

    for(int n : tamanhos){

      vector<string> amostra(dados.begin(), dados.begin() + n);

      TestarTrie(amostra, tipo, n, saida);
      TestarPatricia(amostra, tipo, n, saida);

    }
  }

  vector<string> tipos_inteiros = {"aleatorio","ordenado","decrescente"};

  for(string tipo : tipos_inteiros){

    string nome_arquivo = "data/ints_" + tipo + ".csv";
    vector<int> dados = LerInteiros(nome_arquivo);

    for(int n : tamanhos){

      vector<int> amostra(dados.begin(), dados.begin() + n);

      TestarSplay(amostra, tipo, n, saida);
      TestarTreap(amostra, tipo, n, saida);

    }
  }

  vector<vector<double>> pontos = LerPontos("data/pontos_uniforme.csv");

  for(int n : tamanhos){

    vector<vector<double>> amostra(pontos.begin(),pontos.begin() + n);

    TestarKDTree(amostra, "uniforme", n, saida);

  }

  saida.close();

  return 0;
}