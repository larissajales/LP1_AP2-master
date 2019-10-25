#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H



#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>



using namespace std;

class veiculo{
	private: 
		string marca; 
		double preco;
		string chassi; 
		

//Getters e Setters
	public: 	

		string getMarca();
		string setMarca(string marca_); 
		double getPreco();
		double setPreco(double preco_); 
		string getChassi();
		string setChassi(string chassi_);

	
};

string veiculo::setMarca(string marca_){
	marca=marca_;
	return marca;
}
double veiculo::setPreco(double preco_){
	preco = preco_;
	return preco;

}
string veiculo::setChassi(string chassi_){
	chassi = chassi_;
	return chassi;
}


#endif // AUTOMOVEL_H
