#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include<iostream>
#include <fstream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>


#include "veiculo.h"
#include "automovel.h"
#include "moto.h"
#include "caminhao.h"


using namespace std;


class concessionaria{

private:
	string nome;
	string primeiro_nome;
	string sobrenome;
	string cnpj;
	vector<automovel*> listaConc_A;
	vector<moto*> listaConc_M;
	vector<caminhao*> listaConc_C;

public:
	static int numeroConc;

	//construtor
	concessionaria();

	// destrutor
//	~concessionaria();


	concessionaria(string nome_,string cnpj_, const vector<automovel*>lista_A,const vector<moto*>lista_M,const vector<caminhao*>lista_C);
	concessionaria(string nome_, string primeiro_nome_,string sobrenome_,string cnpj_, const vector<automovel*>lista_A,const vector<moto*>lista_M,const vector<caminhao*>lista_C);
	
	string get_nome();
	string get_primeiro_nome();
	string get_sobrenome();
	string get_cnpj();
	
	int getSizeLista_A();
	int getSizeLista_M();
	int getSizeLista_C();
	

	bool add_carro();
	bool lista_carro();
	bool add_automovel(string marca, double preco, string chassi,int motor,string data_);
	bool add_moto(string marca, double preco, string chassi,int modelo,string data_);
	bool add_caminhao(string marca, double preco, string chassi,int carga,string data_);
	int estoque();
	
	
	bool operator==(concessionaria a){
		return a.get_cnpj() == cnpj;
	}


	friend ostream& operator<< (ostream &o, concessionaria &concessionaria);
	friend ofstream& operator<< (ofstream &o, concessionaria &concessionaria);
	bool operator==(const concessionaria &conc) const;


};

#endif 
