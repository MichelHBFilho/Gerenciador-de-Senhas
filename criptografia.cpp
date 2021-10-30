#include <string>
#include <cstdlib>
#include <array>
#include <ctime>
#include "criptografia.hpp"

std::array<int, 32> criptografa(std::string senha) {
	std::array<int, 32> senhaEmASCII = paraASCII(senha);
	salvaChave(senhaEmASCII);
	for (int i = 0; i < 31; i++) {
		senhaEmASCII[i] = senhaEmASCII[i] * senhaEmASCII[31];
	}
	return senhaEmASCII;
}

std::array<int, 32> paraASCII(std::string& senha) {
	std::array<int, 32> senhaEmASCII;
	for (int i = 0; i < 32; i++) {
		senhaEmASCII[i] = 0;
	}
	for (int i = 0; i < senha.size(); i++) {
		senhaEmASCII[i] = (int)senha[i];
	}
	return senhaEmASCII;
}

int criaChave() {
	int chave = (rand() * time(NULL) / 11) % 300;
	return chave;
}

void salvaChave(std::array<int, 32>& senha) {
	senha[31] = criaChave();
}