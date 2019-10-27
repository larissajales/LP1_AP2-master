#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "gerenciar.h"
#include "moto.h"
#include "veiculo.h"
#include "concessionaria.h"

using namespace std;

moto::moto(){
	setMarca("");
	setPreco(0);
	setChassi("");
	setModelo(0);
	//++numeroCarros;
}

moto::moto(string marca_, double preco_, string chassi_,int modelo_){
	setMarca(marca_);
	setPreco(preco_);
	setChassi(chassi_);
	setModelo(modelo_);
	//++numeroCarros;
}
//moto::~moto(){
//	--numeroCarros;
//}

int moto::getModelo(){
	return modelo;
}

void moto::setModelo(int modelo_){
	modelo = modelo_;
}

ostream& operator<< (ostream &o, moto &veiculo_){
	o << "*********MOTO**********" << endl
	  << "> Marca: " << veiculo_.getMarca() << endl
	  << "> Preco: " << veiculo_.getPreco() << endl
	  << "> Modelo: " << veiculo_.getModelo()<< " (1-ESPORTIVO , 2-NORMAL)"<< endl
	  << "> Numero do Chassi: " << veiculo_.getChassi() << endl;
	return o;
}
ofstream& operator<< (ofstream &o, moto &veiculo){
	o << "\"\";\"\";\""<< veiculo.getMarca()<<"\";\"" << veiculo.getPreco()<<"\";\""<< veiculo.getChassi()<<"\";\"\";" << veiculo.getModelo() <<"\""<< endl;
	return o;
}

//bool moto::operator==(const moto &autom) const {
//	if (this->marca == autom.marca){
//		return true;
//	} else {
//		return false;
//	}
//}

//bool moto::operator==(const std::string &marca) const {
//	if (this->marca == marca){
//		return true;
//	} else {
//		return false;
//	}
//}
