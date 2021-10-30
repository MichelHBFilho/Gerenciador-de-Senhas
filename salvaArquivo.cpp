#include <fstream>
#include <string>
#include <array>
#include "Conta.hpp"
#include "inputs.hpp"
#include "salvaArquivo.hpp"
#include <iostream>
void salvaNoArquivo(Conta& conta) {
	std::ofstream arquivo;
	arquivo.open("senhas.txt", std::ios::app);

	if (!arquivo.is_open()) {
		std::cout << "Erro ao abrir o arquivo" << std::endl;
		exit(1);
	}

	arquivo << conta.servico << std::endl;
	arquivo << conta.usuario << std::endl;
	for (int i = 0; i < 32; i++) {
		arquivo << conta.senha[i] << " ";
	}
	arquivo << std::endl;
	arquivo.close();
}