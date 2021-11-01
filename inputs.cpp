#include <iostream>
#include <array>
#include "Conta.hpp"
#include "criptografia.hpp"
#include "inputs.hpp"
Conta inputs() {
	std::cout << "Serviço: ";
	std::string servico;
	std::cin >> servico;
	std::cout << std::endl;

	std::cout << "Usuario: ";
	std::string usuario;
	std::cin >> usuario;
	std::cout << std::endl;

	std::cout << "Senha: ";
	std::string senha;
	std::cin >> senha;
	std::cout << std::endl;

	std::array<int, 32> senhaCriptografada = criptografa(senha);

	return Conta(servico, usuario, senhaCriptografada);
}