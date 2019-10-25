#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef CAMINHAO_H
#define CAMINHAO_H



#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>



using namespace std;

class caminhao : public veiculo{
	private: 
		int tipo_carga;  
		

	public: 
		static int numeroCarros;

		caminhao();
		caminhao(string marca, double preco, string chassi, int tipo_carga_);
		~caminhao();
		int setTipo_carga();
		void getTipo_carga(int tipo_carga_);

		friend ostream& operator << (ostream &o, caminhao &veiculo);

		bool operator==(const caminhao &cam) const;

		bool operator==(const string &marca) const;
	
};




#endif // AUTOMOVEL_H
