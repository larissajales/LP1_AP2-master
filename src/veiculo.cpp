#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <ctime>

#include "veiculo.h"


void veiculo::setMarca(string marca_){
	marca = marca_;
}
void veiculo::setPreco(double preco_){
	preco = preco_;
}
void veiculo::setChassi(string chassi_){
	chassi = chassi_;
}
void veiculo::setData(){
	string data;
  	time_t now = time(0);
	data = ctime(&now);
	
	string aux;
	int tamanho = data.size() -1;
	for (int i = 0; i < tamanho; i++){
		aux += data[i];
	}
	setData(aux);
}

void veiculo::setData(string data_){	
	data = data_;
}

//**************************************************************************
string veiculo::getMarca(){
	return marca;
}
string veiculo::getData(){
	return data;
}

double veiculo::getPreco(){
	return preco;
}
string veiculo::getChassi(){
	return chassi;
}

