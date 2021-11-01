#include <iostream>
#include <vector>
#include "cabecalho.hpp"
#include "inputs.hpp"
#include "salvaArquivo.hpp"
#include "Conta.hpp"
#include "leArquivo.hpp"
#include "descriptografa.hpp"
using namespace std;

#if defined(_WIN32) || defined(WIN32)
void limpaTela() {
	system("cls");
	}
#else
void limpaTela() {
	system("clear");
	}
#endif

void login() {
	string tentativa;
	string senhaMestra = leSenhaMestre();
	cout << "****** DIGITE SUA SENHA *****" << endl;
	cin >> tentativa;
	if (tentativa != senhaMestra) {
		cout << "Senha incorreta" << endl;
		exit(200);
	}
	cout << "Senha correta :)" << endl;
	limpaTela();
}

int main() {
#if defined(_WIN32) || defined(WIN32)
	system("chcp 1252");
#endif

	limpaTela();

	cabecalho();
	login();

	vector<Conta> contas = leArquivo();

	while (true) {
		cout << "O que deseja fazer? " << endl;
		cout << "1- Listar serviços" << endl;
		cout << "2- Ver senhas" << endl;
		cout << "3- Pesquisar por serviço" << endl;
		cout << "4- Adicionar novo serviço" << endl;
		cout << "5- Sair" << endl;

		int op;
		cin >> op;
		
		limpaTela();

		switch (op) {
		case 1: {
			cout << "Você tem os seguintes serviços registrados: " << endl;
			for (Conta i : contas) {
				cout << i.servico << endl;
			}
			break;
		}
		case 2: {
			login();
			for (Conta i : contas) {
				cout << i.servico << ":" << endl;
				cout << "Usuario de login: " << i.usuario << endl;
				cout << "Senha: " << descriptografa(i.senha) << endl;
			}
			break;
		}
		case 3: {
			cout << "Qual serviço você deseja encontrar? ";
			string servico;
			cin >> servico;
			bool achou = false;

			for (Conta i : contas) {
				if (i.servico == servico) {
					login();
					cout << i.servico << ":" << endl;
					cout << "Usuario de login: " << i.usuario << endl;
					cout << "Senha: " << descriptografa(i.senha) << endl;
					achou = true;
					break;
				}
				continue;
			}

			if (achou) break;
			cout << "Não encontramos este serviço em nosso banco" << endl;
			break;
		}
		case 4: {
			Conta conta = inputs();
			salvaNoArquivo(conta, contas);
			break;
		}
		case 5: {
			cout << "Obrigado, tchau!" << endl;
			exit(0);
		}
		}
		limpaTela();
	}
}