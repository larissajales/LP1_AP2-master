#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "gerenciar.h"
#include "caminhao.h"
#include "veiculo.h"
#include "concessionaria.h"

using namespace std;

caminhao::caminhao(){
	setMarca("");
	setPreco(0);
	setChassi("");
	setTipo_carga(0);
	//++numeroCarros;
}

caminhao::caminhao(string marca_, double preco_, string chassi_,int tipo_carga_ ){
	setMarca(marca_);
	setPreco(preco_);
	setChassi(chassi_);
	setTipo_carga(tipo_carga_);
	//++numeroCarros;
}
//caminhao::~caminhao(){
//	--numeroCarros;
//}

int caminhao::getTipo_carga(){
	return tipo_carga;
}

void caminhao::setTipo_carga(int tipo_carga_){
	tipo_carga = tipo_carga_;
}

ostream& operator<< (ostream &o, caminhao &veiculo_){
	o << "*********CAMINHAO******" << endl
	  << "> Marca: " << veiculo_.getMarca() << endl
	  << "> Preco: " << veiculo_.getPreco() << endl
	  << "> Tipo de carga: " << veiculo_.getTipo_carga() << " (1 NORMAL, 2 RISCO)" << endl
	  << "> Numero do Chassi: " << veiculo_.getChassi() << endl;
	return o;
}
ofstream& operator<< (ofstream &o, caminhao &veiculo){
	o << "\"\";\"\";\""<< veiculo.getMarca()<<"\";\"" << veiculo.getPreco()<<"\";\""<< veiculo.getChassi()<<"\";\";\";\"" << veiculo.getTipo_carga() <<"\""<< endl;
	return o;
}

//bool caminhao::operator==(const caminhao &autom) const {
//	if (this->marca == autom.marca){
//		return true;
//	} else {
//		return false;
//	}
//}

//bool caminhao::operator==(const std::string &marca) const {
//	if (this->marca == marca){
//		return true;
//	} else {
//		return false;
//	}
//}
