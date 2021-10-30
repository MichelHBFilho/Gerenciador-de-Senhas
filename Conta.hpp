#pragma once
#include <string>
#include <array>
class Conta {
public:
	std::string usuario;
	std::string servico;
	std::array<int, 32> senha;
	Conta(std::string servico, std::string usuario, std::array<int, 32> senha) :
		servico(servico),
		usuario(usuario),
		senha(senha) {};
};

