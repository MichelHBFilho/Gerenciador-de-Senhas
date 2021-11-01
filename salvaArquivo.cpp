#include <fstream>
#include <string>
#include <array>
#include "Conta.hpp"
#include "inputs.hpp"
#include "salvaArquivo.hpp"
#include <iostream>
#include <vector>
#include "leArquivo.hpp"
#include "criptografia.hpp"
void salvaNoArquivo(Conta& conta, std::vector<Conta>& contas) {
	std::array<int, 32> senhaMestra = criptografa(leSenhaMestre());
	std::ofstream arquivo;
	arquivo.open("senhas.txt");
	contas.push_back(conta);
	arquivo << contas.size() << std::endl;
	
	for (int i : senhaMestra) {
		arquivo << i << " ";
	}
	arquivo << std::endl;

	for (Conta i : contas) {
		arquivo << i.servico << std::endl;
		arquivo << i.usuario << std::endl;
		
		for (int j = 0; j < 32; j++) {
			arquivo << i.senha[j] << " ";
		}
		arquivo << std::endl;
	}
}