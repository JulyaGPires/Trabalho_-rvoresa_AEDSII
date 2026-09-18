#ifndef TESTES_HPP
#define TESTES_HPP
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void TestarTrie(vector<string> &dados, string tipo, int n, ofstream &saida);
void TestarPatricia(vector<string> &dados, string tipo, int n, ofstream &saida);
void TestarSplay(vector<int> &dados, string tipo, int n, ofstream &saida);
void TestarTreap(vector<int> &dados, string tipo, int n, ofstream &saida);
void TestarKDTree(vector<vector<double>> &dados, string tipo, int n, ofstream &saida);


#endif