#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "gerenciar.h"
#include "concessionaria.h"

#include "veiculo.h"
#include "automovel.h"
#include "moto.h"
#include "caminhao.h"

using namespace std;

concessionaria::concessionaria(){
	nome = "";
	cnpj = 0;

}

concessionaria::concessionaria(std::string nome_, int cnpj_, const vector<automovel*>lista_A, const vector<moto*>lista_M,const vector<caminhao*>lista_C){
	nome = nome_;
	cnpj = cnpj_;
	listaConc_A = lista_A;
	listaConc_M = lista_M;
	listaConc_C = lista_C;
	++(++numeroConc);
}



string concessionaria::get_nome(){
	return nome; 
}

int concessionaria::get_cnpj(){
//	int cnpj_ = 0;

	//cnpj = cnpj_;
	return cnpj; 
}



bool concessionaria::add_carro(){
	string chassi;
	string marca;
	double preco;
	int motor;
	int carga;
	int modelo;
	int escolha;
	cout << endl << "-> informe o tipo de Veiculo:";
	cout << endl << "-> automovel ........ 1";
	cout << endl << "-> Moto.............. 2";
	cout << endl << "-> Caminhao.......... 3"<< endl;
	cin >> escolha;
	
	
	
	if (escolha == 1){
		cout << endl << "-> Digite os dados do carro";

		cout << endl << "Numero do Chassi: "<< endl;
		cin>>chassi;
	
		cout << endl << "Marca: "<< endl;
		cin>>marca;
	
		cout << endl << "valor: "<< endl;	
		cin >> preco;
		
		cout << endl << "Tipo do motor:\n(1 para gasolina, 2 para eletrico): "<< endl;	
		cin >> motor;
		
		automovel *autom = new automovel(marca, preco, chassi,motor);
		
		//for (vector<automovel*>::iterator it = listaConc_A.begin(); it != listaConc_A.end(); ++it){
		//	if (**it == *autom){
		//		cout << endl << "Carro ja cadastrado. Operacao CANCELADA!" << endl;
		//		return false;	
		//	}
		//}
		
		listaConc_A.push_back(autom);
		
	
	}
	if (escolha == 2){
		cout << endl << "-> Digite os dados do carro";

		cout << endl << "Numero do Chassi: "<< endl;
		cin>>chassi;
	
		cout << endl << "Marca: "<< endl;
		cin>>marca;
	
	
		cout << endl << "valor: "<< endl;	
		cin >> preco;
		
		cout << endl << "Modelo:\n(1 para esportio, 2 para comum): "<< endl;	
		cin >> modelo;
		
		moto *autom = new moto(marca, preco, chassi,modelo);
		
		//for (vector<moto*>::iterator it = listaConc_M.begin(); it != listaConc_M.end(); ++it){
		//	if (**it == *autom){
		//		cout << endl << "Moto ja cadastrada. Operacao CANCELADA!" << endl;
		//		return false;	
		//	}
		//}
		listaConc_M.push_back(autom);
	}
	if (escolha == 3){
		cout << endl << "-> Digite os dados do carro";

		cout << endl << "Numero do Chassi: "<< endl;
		cin>>chassi;
	
		cout << endl << "Marca: "<< endl;
		cin>>marca;
	
		cout << endl << "valor: "<< endl;	
		cin >> preco;
		
		cout << endl << "Tipo da carga:\n(1 para normal, 2 para de risco): "<< endl;	
		cin >> carga;
		
		caminhao *autom = new caminhao(marca, preco, chassi,carga);
		
	//	for (vector<caminhao*>::iterator it = listaConc_C.begin(); it != listaConc_C.end(); ++it){
	//		if (**it == *autom){
	//			cout << endl << "Caminhao ja cadastrado. Operacao CANCELADA!" << endl;
	//			return false;	
	//		}
	//	}
		listaConc_C.push_back(autom);
	}
	else if(escolha != 1 && escolha !=2 && escolha != 3){
		cout << endl << "Opcao invalida.\n\n";
		
	}
	return true;
}



   ostream& operator<<(ostream &o, concessionaria &concessionaria){
	for (vector<automovel*>::iterator i = concessionaria.listaConc_A.begin(); i != concessionaria.listaConc_A.end(); ++i)
	{
		o << (**i) << endl;
	}
	for (vector<moto*>::iterator i = concessionaria.listaConc_M.begin(); i != concessionaria.listaConc_M.end(); ++i)
	{
		o << (**i) << endl;
	}
	for (vector<caminhao*>::iterator i = concessionaria.listaConc_C.begin(); i != concessionaria.listaConc_C.end(); ++i)
	{
		o << (**i) << endl;
	}
	return o;
}
ofstream& operator<<(ofstream &of, concessionaria &concessionaria){
	for (vector<automovel*>::iterator i = concessionaria.listaConc_A.begin(); i != concessionaria.listaConc_A.end(); ++i)
	{
		of << (**i);
	}
	
	return of;
}




bool concessionaria::operator==(const concessionaria &conc) const{
	if (this->nome == conc.nome){
		return true;
	} else {
		return false;
	}
}
