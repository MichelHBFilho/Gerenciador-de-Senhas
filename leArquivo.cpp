#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "Conta.hpp"
#include "descriptografa.hpp"
#include "criptografia.hpp"

void criaSenhaMestra() {
	std::ofstream arquivo;
	arquivo.open("senhas.txt", std::ios::app);

	if (!arquivo.is_open()) return;

	std::string senhaMestra;
	
	std::cout << "Qual vai ser sua senha mestra? ";
	std::cin >> senhaMestra;

	std::array<int, 32> senhaMestraCriptografada = criptografa(senhaMestra);

	for (int i = 0; i < 32; i++) {
		arquivo << senhaMestraCriptografada[i] << " ";
	}

	arquivo.close();
}

std::string leSenhaMestre() {
	std::ifstream arquivo;
	std::string senhaMestra;
	arquivo.open("senhas.txt");
	arquivo >> senhaMestra;
	std::array<int, 32> senhaMestraCriptografada;
	for (int i = 0; i < 32; i++) {
		std::string parte;
		arquivo >> parte;
		try {
			senhaMestraCriptografada[i] = stoi(parte);
		}
		catch (std::invalid_argument) {
			std::cout << "Você ainda não tem senha mestra" << std::endl;
			arquivo.close();
			criaSenhaMestra();
			return leSenhaMestre();
		}
	} 
	senhaMestra = descriptografa(senhaMestraCriptografada);
	arquivo.close();
	return senhaMestra;
}

std::vector<Conta> leArquivo() {
	std::ifstream arquivo;
	arquivo.open("senhas.txt");
	if (!arquivo.is_open()) {
		std::cout << "Erro ao abrir o arquivo" << std::endl;
		exit(1);
	}

	int numeroDeServicos = 0;
	arquivo >> numeroDeServicos;

	std::vector<Conta> contas;

	for (int i = 0; i < 32; i++) {
		int pula;
		arquivo >> pula;
	}
	
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

		contas.push_back(Conta(servico, usuario, senhaCompleta));
	}

	arquivo.close();
	return contas;
}