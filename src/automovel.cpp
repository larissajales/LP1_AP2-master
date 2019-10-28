#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "gerenciar.h"
#include "automovel.h"
#include "veiculo.h"
#include "concessionaria.h"

using namespace std;

automovel::automovel(){
	veiculo::setMarca("");
	veiculo::setPreco(0);
	veiculo::setChassi("");
	setTipo_motor(0);
	setData();
	
	//++numeroCarros;
}

automovel::automovel(string marca_, double preco_, string chassi_,int motor_ ){
	tipo_motor = motor_;
	setMarca(marca_);
	setPreco(preco_);
	setChassi(chassi_);
	setData();	
	//++numeroCarros;
}
automovel::automovel(string marca_, double preco_, string chassi_,int motor_, string data_ ){
	tipo_motor = motor_;
	setMarca(marca_);
	setPreco(preco_);
	setChassi(chassi_);
	setData(data_);	
	//++numeroCarros;
}

//automovel::~automovel(){
//	--numeroCarros;
//}

int automovel::getTipo_motor(){
	return tipo_motor;
}

void automovel::setTipo_motor(int motor_){
	tipo_motor = motor_;
}


ostream& operator<< (ostream &o, automovel &veiculo){
	o << "*******AUTOMOVEL*******" << endl
	  << "> Marca: " << veiculo.getMarca() << endl
	  << "> Preco: " << veiculo.getPreco() << endl
	  << "> Tipo motor: " << veiculo.getTipo_motor() << " (1-GASOLINA , 2-ELETRICO)"<< endl
	  << "> Data fabricacao: " << veiculo.getData() << endl
	  << "> Numero do Chassi: " << veiculo.getChassi()<< endl;
	return o;
}
ofstream& operator<< (ofstream &o, automovel &veiculo){
	o << endl << ";;;;"<< veiculo.getMarca()<<";" << veiculo.getPreco()<<";"<< veiculo.getChassi()<<";" << veiculo.getTipo_motor() <<";;;"<< veiculo.getData();
	return o;
}

//bool automovel::operator==(const automovel &autom) const {
//	if (this->getMarca = autom.getMarca())
//		return true;
//	} else {
//		return false;
//	}
//}

//bool automovel::operator==(const std::string &marca) const {
//	if (this->getMarca() == marca){
//		return true;
//	} else {
//		return false;
//	}
//}
