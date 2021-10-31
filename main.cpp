#include <iostream>
#include <vector>
#include "cabecalho.hpp"
#include "inputs.hpp"
#include "salvaArquivo.hpp"
#include "Conta.hpp"
#include "leArquivo.hpp"
#include "descriptografa.hpp"
using namespace std;
string senhaMestra;
int main() {
	cabecalho();
	cout << "O que deseja fazer? " << endl;
	cout << "Listar servicos" << endl;
	leArquivo();
}