#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

#include "gerenciar.h"
#include "veiculo.h"
#include "automovel.h"
#include "concessionaria.h"

using namespace std;

automovel::automovel(){
	Marca = " ";
	setMarca(Marca);
	setPreco(0);
	chassi = " ";
	setChassi(chassi);
	setTipo_motor(0);
	++numeroCarros;
}

automovel::automovel(string marca_, double preco_, string chassi_,int motor_ ){
	setMarca(marca_);
	setPreco(preco_);
	setChassi(chassi_);
	setTipo_motor(motor_);
	++numeroCarros;
}
automovel::~automovel(){
	--numeroCarros;
}

int getTipo_motor(){
	return = tipo_motor;
}

void automovel::setTipo_motor(int motor_){
	tipo_motor = motor_;
}


ostream& operator<< (ostream &o, automovel &veiculo){
	o << "> Marca: " << veiculo.getMarca() << endl
	  << "> Preco: " << veiculo.getPreco() << endl
	  << "> Tipo motor: " << automovel.getTipo_motor() << endl
	  << "> Numero do Chassi: " << veiculo.getChassi() << endl;
	return o;
}

bool automovel::operator==(const automovel &autom) const {
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
