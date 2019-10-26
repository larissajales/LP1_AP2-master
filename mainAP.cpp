#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "veiculo.h"
#include "gerenciar.h"
#include "concessionaria.h"
#include "automovel.h"
#include "moto.h"
#include "caminhao.h"

using namespace std;
gerenciar listaConc;

//int automovel::numeroCarros = 0;
int concessionaria::numeroConc = 0;

int main (int argc, char const *argv[]){
	int x = -1;
	while (x!= 0){
		cout << endl << "++++++++++++++++++++++++++++++++"<<endl
		<< endl << "Escolha a opcao desejada"<<endl
		<< "Digite 1 - Adicionar Automovel "<<endl
		<< "Digite 2 - Criar Concessionaria"<< endl
		<< "Digite 3 - Lista de Automoveis"<< endl
		<< "Digite 0 - Sair"<< endl
		<< "++++++++++++++++++++++++++++++++"<<endl
		<< endl<< "Digite sua Escolha: " <<endl;
	
		cin >> x; 

		switch (x){
			case 1: 
					listaConc.cadastrarCarro();
					break;
			case 2: 
					listaConc.criarconcessionaria();
					break;
			case 3:
					listaConc.estoques();
					break;
			case 0:
					cout<<endl<< "Ate mais!" << endl;
					return 0;
			default:
			cin.clear();
			cin.ignore(200,'\n');
			cout << endl << "Entrada inválida, digite novamente" <<endl;
		}
	}
	return 0;


}
