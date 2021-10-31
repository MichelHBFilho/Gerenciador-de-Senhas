#include <iostream>
#include <vector>
#include <string>
#include <array>
#include "Conta.hpp"
#include "descriptografa.hpp"
void imprimeContas(std::vector<Conta> contas) {
	for (Conta i : contas) {
		std::cout << "Serviço: " << i.servico << std::endl;
		std::cout << "Usuario: " << i.usuario << std::endl;
		std::cout << "Senha:   " << descriptografa(i.senha) << std::endl;

	}
}

std::string descriptografa(std::array<int, 32> senha) {
	char senhaDescriptografada[32] = "";
	for (int i = 0; i < 31; i++) {
		senhaDescriptografada[i] =  char(senha[i] / senha[31]);
	}
	return std::string(senhaDescriptografada);
}
