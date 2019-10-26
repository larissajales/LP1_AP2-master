#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>


#include "veiculo.h"


void veiculo::getMarca(string marca_){
	marca=marca_;
}
void veiculo::getPreco(double preco_){
	preco = preco_;
}
void veiculo::getChassi(string chassi_){
	chassi = chassi_;
}
//**************************************************************************
string veiculo::setMarca(){

	return marca;
}
double veiculo::setPreco(){
	return preco;

}
string veiculo::setChassi(){

	return chassi;
}

