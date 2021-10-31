#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "Conta.hpp"
#include "descriptografa.hpp"
extern std::string senhaMestra;
std::vector<Conta> leArquivo() {
	std::ifstream arquivo;
	arquivo.open("senhas.txt");
	if (!arquivo.is_open()) {
		std::cout << "Erro ao abrir o arquivo" << std::endl;
		exit(1);
	}

	int numeroDeServicos = 0;
	arquivo >> numeroDeServicos;

	std::array<int, 32> senhaMestraCriptografada;
	for (int i = 0; i < 32; i++) {
		std::string parte;
		arquivo >> parte;
		senhaMestraCriptografada[i] = stoi(parte);
	}
	senhaMestra = descriptografa(senhaMestraCriptografada);
	
	std::vector<Conta> contas;

	for (int i = 0; i < numeroDeServicos; i++) {
		std::string servico;
		std::string usuario;
		std::string senha;
		std::array<int, 32> senhaCompleta;

		arquivo >> servico;
		arquivo >> usuario;


		for (int j = 0; j < 32; j++) {
			arquivo >> senha;
			senhaCompleta[j] = stoi(senha);
		}
		arquivo.close();
		contas.push_back(Conta(servico, usuario, senhaCompleta));
	}

	return contas;
}