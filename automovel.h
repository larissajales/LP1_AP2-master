#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H



#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

#include "veiculo.h"

using namespace std;

class automovel : public veiculo{
	private: 
		int tipo_motor;  
		

	public: 
		//static int numeroCarros;

		automovel();
		automovel(string marca, double preco, string chassi, int tipo_motor);
		//~automovel();
		int getTipo_motor();
		void setTipo_motor(int motor_);

		friend ostream& operator << (ostream &o, automovel &veiculo);
		friend ofstream& operator << (ofstream &o, automovel &veiculo);
	//	bool operator==(const automovel &autom) const;

	//	bool operator==(const string &marca) const;
	
};




#endif // AUTOMOVEL_H
