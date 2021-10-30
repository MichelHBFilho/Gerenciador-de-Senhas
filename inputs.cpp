#include <iostream>
#include "Conta.hpp"
#include "inputs.hpp"
Conta inputs() {
	std::cout << "Qual o serviço? ";
	std::string servico;
	std::cin >> servico;
	std::cout << std::endl;

	std::cout << "O seu usuario de login? ";
	std::string usuario;
	std::cin >> usuario;
	std::cout << std::endl;

	std::cout << "E a senha? ";
	std::string senha;
	std::cin >> senha;
	std::cout << std::endl;

	return Conta(servico, usuario, senha);
}