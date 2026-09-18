#include "Leitura_Arquivo.hpp"
#include <fstream>
#include <sstream>

using namespace std;


vector<string> LerStrings(string nome_arquivo){

  vector<string> dados;
  ifstream arquivo(nome_arquivo);

  string linha;
  getline(arquivo, linha);

  while(getline(arquivo, linha)){

    if(!linha.empty() && linha.back() == '\r'){
        linha.pop_back();
    }

    if(!linha.empty()){
        dados.push_back(linha);
    }
  }

  return dados;
}

vector<int> LerInteiros(string nome_arquivo){

  vector<int> dados;
  ifstream arquivo(nome_arquivo);

  string linha;
  getline(arquivo, linha);

  while(getline(arquivo, linha)){

    if(!linha.empty() && linha.back() == '\r'){
        linha.pop_back();
    }

    if(!linha.empty()){
        dados.push_back(stoi(linha));
    }
  }

  return dados;
}

vector<vector<double>> LerPontos(string nome_arquivo){

  vector<vector<double>> pontos;
  ifstream arquivo(nome_arquivo);

  string linha;
  getline(arquivo, linha);

  while(getline(arquivo, linha)){

    stringstream ss(linha);
    string valor;
    vector<double> ponto;

    while(getline(ss, valor, ',')){
        ponto.push_back(stod(valor));
    }

    if(ponto.size() == 3){
        pontos.push_back(ponto);
    }
  }

  return pontos;
}