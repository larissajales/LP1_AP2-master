#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "gerenciar.h"
#include "concessionaria.h"

#include "veiculo.h"
#include "automovel.h"
#include "moto.h"
#include "caminhao.h"

using namespace std;
using std::string;
using std::getline;




concessionaria gerenciar::criarconcessionaria(){
	string nome;
	int cnpj;
	vector<automovel*> listaConc_A;
	vector<moto*> listaConc_M;
	vector<caminhao*> listaConc_C;

	
	cout << "Informe o nome da concessionaria: ";
	cin.ignore(200,'\n');
	getline(cin,nome);
	

	cout << endl<< "Informe o CNPJ da concessionaria: ";
	cin >> cnpj; 
	

	cout << "NOME:" << nome << endl;
	concessionaria *novaConc = new concessionaria(nome,cnpj,listaConc_A,listaConc_M,listaConc_C);
	statusConc status = inexistente;
	
	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
			if ((**it).get_nome()== nome){
				cout << endl << "Concessionaria ja cadastrado. Operacao CANCELADA!" << endl;
				status = existe;
			}
		}

	if (status == inexistente){
			listaLoja.push_back(novaConc);
			cout<< endl << "Concessionaria Inaugurada."<< endl;
	}

	return *novaConc;

}

concessionaria gerenciar::criarconcessionariaCSV(){
	string arq,NOME,nomee,CNPJ,MARCA,PRECO,CHASSI,MOTOR,MODELO,CARGA; 
	int cnpjj,motorr,modeloo,cargaa;
	double precoo;	
	vector<automovel*> listaConc_A;
	vector<moto*> listaConc_M;
	vector<caminhao*> listaConc_C;
	
	cout << "Informe o nome do arquivo: (SEM INCLUIR .CSV)";
	cin>>arq;
	
	ifstream arquivoE;
	arquivoE.open(arq+".csv");	
	if(arquivoE.is_open()){		
		while(arquivoE.good()){
			getline	(arquivoE,NOME,';');
			getline	(arquivoE,CNPJ,';');
			getline	(arquivoE,MARCA,';');
			getline	(arquivoE,PRECO,';');
			getline	(arquivoE,CHASSI,';');
			getline	(arquivoE,MOTOR,';');
			getline	(arquivoE,MODELO,';');
			getline	(arquivoE,CARGA,'\n');
			
			if (CNPJ != "" && CNPJ != "CNPJ"){
				cnpjj = stoi(string (CNPJ));
				nomee = NOME;
				break;		
			}
		}
		for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
			if ((**it).get_nome()== nomee){
				cout << endl << "Concessionaria ja cadastrado. Operacao CANCELADA!" << endl;
				return **it;
				arquivoE.close();
			}
		}
		if(arquivoE.is_open()){
	
		concessionaria *novaConc = new concessionaria(nomee,cnpjj,listaConc_A,listaConc_M,listaConc_C);
		listaLoja.push_back(novaConc);		
	 	while(arquivoE.good()){
			getline	(arquivoE,NOME,';');
			getline	(arquivoE,CNPJ,';');
			getline	(arquivoE,MARCA,';');
			getline	(arquivoE,PRECO,';');
			getline	(arquivoE,CHASSI,';');
			getline	(arquivoE,MOTOR,';');
			getline	(arquivoE,MODELO,';');
			getline	(arquivoE,CARGA,'\n');
			
			if (CNPJ != "" && CNPJ != "CNPJ"){
				cnpjj = stoi(string (CNPJ));			
					concessionaria *novaConc = new concessionaria(NOME,cnpjj,listaConc_A,listaConc_M,listaConc_C);
					listaLoja.push_back(novaConc);				
				}
			else{
				if (MOTOR != "" and MOTOR != "MOTOR"){
				motorr = stoi(string (MOTOR));	
				precoo = stod(string (PRECO));	
				novaConc->add_automovel(MARCA, precoo, CHASSI,motorr);	
							
				}
				else if (MODELO != "" and MODELO != "MODELO"){
					modeloo = stoi(string (MODELO));	
					precoo = stod(string (PRECO));	
					novaConc->add_moto(MARCA,precoo, CHASSI,modeloo);				
				}
				else if (CARGA != "" and CARGA != "CARGA"){
					cargaa = stoi(string (CARGA));	
					precoo = stod(string (PRECO));	
					novaConc->add_caminhao(MARCA,precoo, CHASSI,cargaa);				
				}
			}	
		}
		cout << endl << "Concessionaria cadastrado." << endl;
		return *novaConc;
		arquivoE.close();
		}	
	}	
	else{
		cout << "Erro ao abrir arquivo. Verifique se o nome esta correto. "<< endl;	
	}
	
}


void gerenciar::salvarConcessionaria(){
	cout << endl << "Deseja salvar qual concessionaria? " <<endl<< "Concessionarias:" << endl << endl;
	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		cout << (**it).get_nome() << endl;
	}
	cout << endl << "Digite a concessionaria: ";
	string nome;
	cin.ignore(200,'\n');
	getline(cin,nome);
	statusConc status = inexistente;
		
	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		if ((**it).get_nome() == nome){
			status = existe;
			ofstream arquivo;
			arquivo.open(nome+".csv");
			arquivo << "NOME;CNPJ;MARCA;PRECO;CHASSI;MOTOR;MODELO;CARGA"<< endl;
			arquivo << nome <<";"<< (**it).get_cnpj() << ";;;;;;";
			for ( vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
				if ((**it).get_nome() == nome){
				
				arquivo << (**it);
				}
			}
			cout << endl << "Concessionaria " << nome << " salva com sucesso."<< endl;
			
		} 
	}
}



void gerenciar::cadastrarCarro(){

	cout << endl << "Deseja cadastrar o carro em qual concessionaria? " <<endl<< "Concessionarias:" << endl << endl;


	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		cout << (**it).get_nome() << endl;
	}

	cout << endl << "Digite a concessionaria: ";
	string nome;
	cin.ignore(200,'\n');
	getline(cin,nome);
	statusConc status = inexistente;

	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		if ((**it).get_nome() == nome){
			status = existe;
			if ((**it).add_carro()){
				status = carroCadastrado;
			} 
		}
	}
	if (status == inexistente){
		cout << endl << "Concessionaria nao encontrada. Tente novamente." << endl;
	} 
	else if (status == carroCadastrado){
		cout << endl << "Veiculo cadastrado." << endl;
	} 
	else{
		cout << endl << "Veiculo ja cadastrado." << endl;
	}
	return;
}

bool gerenciar::estoques(){

	cout << endl << "Estoque de qual concessionaria quer acessar? " << endl << "Concessionarias:" << endl << endl;
			  
	for ( vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		cout << (**it).get_nome() << endl;
	}

	cout << endl << "Digite a concessionaria: ";
	string nome;
	cin.ignore(200,'\n');
	getline(cin,nome);

	for ( vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		if ((**it).get_nome() == nome){
			cout << endl << " O estoque da " << nome << " possui: "<< endl;
			cout << (**it);
			return true;
		}
	}
	cout << endl << "Concessionaria nao encontrada. Tente novamente." << endl;
	return false;
}




