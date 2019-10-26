#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

#include "gerenciar.h"
#include "moto.h"
#include "veiculo.h"
#include "concessionaria.h"

using namespace std;

moto::moto(){
	Marca = " ";
	setMarca(Marca);
	setPreco(0);
	chassi = " ";
	setChassi(chassi);
	setModelo(0);
	++numeroCarros;
}

moto::moto(string marca_, double preco_, string chassi_,int modelo_ ){
	setMarca(marca_);
	setPreco(preco_);
	setChassi(chassi_);
	setModelo(modelo_);
	++numeroCarros;
}
moto::~moto(){
	--numeroCarros;
}

int moto::getModelo(){
	return = modelo;
}

void moto::setModelo(int modelo_){
	modelo = modelo_;
}

ostream& operator<< (ostream &o, moto &veiculo_){
	o << "> Marca: " << veiculo_.getMarca() << endl
	  << "> Preco: " << veiculo_.getPreco() << endl
	  << "> Modelo: " << veiculo_.getModelo()<< endl
	  << "> Numero do Chassi: " << veiculo_.getChassi() << endl;
	return o;
}

bool automovel::operator==(const moto &autom) const {
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
