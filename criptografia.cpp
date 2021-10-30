#include <string>
#include <cstdlib>
int criptografa(std::string senha) {
	int chave1 = rand();
	int chave2 = (rand() * chave1) / chave1 * 43.2;
	return chave1 * chave2;
}