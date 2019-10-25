#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

#include "gerenciar.h"
#include "caminhao.h"
#include "veiculo.h"
#include "concessionaria.h"

using namespace std;

caminhao::caminhao(){
	Marca = " ";
	setMarca(Marca);
	setPreco(0);
	chassi = " ";
	setChassi(chassi);
	setTipo_carga(0);
	++numeroCarros;
}

caminhao::caminhao(string marca_, double preco_, string chassi_,int tipo_carga_ ){
	setMarca(marca_);
	setPreco(preco_);
	setChassi(chassi_);
	setTipo_carga(tipo_carga_);
	++numeroCarros;
}
moto::~moto(){
	--numeroCarros;
}

int moto::getModelo(){
	return = tipo_carga;
}

void moto::setModelo(int tipo_carga_){
	modelo = tipo_carga_;
}

ostream& operator<< (ostream &o, caminhao &veiculo_){
	o << "> Marca: " << veiculo_.getMarca() << endl
	  << "> Preco: " << veiculo_.getPreco() << endl
	  << "> Tipo de carga: " << veiculo_.setTipo_carga()<< endl
	  << "> Numero do Chassi: " << veiculo_.getChassi() << endl;
	return o;
}

bool automovel::operator==(const caminhao &autom) const {
	if (this->marca == autom.marca){
		return true;
	} else {
		return false;
	}
}

bool automovel::operator==(const std::string &marca) const {
	if (this->marca == marca){
		return true;
	} else {
		return false;
	}
}
