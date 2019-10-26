#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef VEICULO_H
#define VEICULO_H

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
		double getPreco();		 
		string getChassi();
		
		string setMarca(std::string marca_); 
		double setPreco(double preco_);
		string setChassi(std::string chassi_);

	
};

#endif // VEICULO_H
