#include <iostream>
#include "cabecalho.hpp"
#include "inputs.hpp"
#include "salvaArquivo.hpp"
#include "Conta.hpp"
using namespace std;
int main() {
	cabecalho();
	Conta conta = inputs();
	salvaNoArquivo(conta);
}