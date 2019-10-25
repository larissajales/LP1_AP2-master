#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef MOTO_H
#define MOTO_H



#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>



using namespace std;

class moto : public veiculo{
	private: 
		int modelo;
	public: 
		static int numeroCarros;

		moto();
		moto(string marca, double preco, string chassi, int modelo,int modelo_);
		~moto();
		int getModelo();
		void setModelo(int modelo_);


		friend ostream& operator << (ostream &o, moto &veiculo_);

		bool operator==(const moto &mot) const;

		bool operator==(const string &marca) const;
	
};




#endif // AUTOMOVEL_H
