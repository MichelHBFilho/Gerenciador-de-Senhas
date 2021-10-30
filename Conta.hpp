#pragma once
#include <string>
class Conta {
public:
	std::string usuario;
	std::string servico;
	std::string senha;
	Conta(std::string servico, std::string usuario, std::string senha) :
		servico(servico),
		usuario(usuario),
		senha(senha) {};
};

