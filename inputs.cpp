#include <iostream>
#include <array>
#include "Conta.hpp"
#include "criptografia.hpp"
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

	std::array<int, 32> senhaCriptografada = criptografa(senha);

	return Conta(servico, usuario, senhaCriptografada);
}