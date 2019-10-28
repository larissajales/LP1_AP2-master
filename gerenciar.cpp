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
	string P_nome;
	string sobrenome;
	string cnpj;
	int pessoa;
	vector<automovel*> listaConc_A;
	vector<moto*> listaConc_M;
	vector<caminhao*> listaConc_C;
	
	cout << "Informe o nome da concessionaria: ";
	cin.ignore(200,'\n');
	getline(cin,nome);
	
	cout << "Informe o tipo de proprietario.\nPessoa fisica ----- 1\nPessoa Juridica --- 2\n";
	cin >> pessoa;
	if(pessoa  == 1){
		cout << endl<< "Informe o nome do proprietario: ";
		cin >> P_nome;
		cout << endl<< "Informe o sobrenome do proprietario: ";
		cin >> sobrenome;
		cnpj = "";
	}
	else if (pessoa == 2){
		cout << endl<< "Informe o CNPJ da concessionaria: ";
		cin >> cnpj;
		sobrenome = "";
		P_nome ="";	
	}

	cout << "NOME:" << P_nome << endl;
	cout << "SOBRENOME:" << sobrenome << endl;
	concessionaria *novaConc = new concessionaria(nome,P_nome,sobrenome,cnpj,listaConc_A,listaConc_M,listaConc_C);
	statusConc status = inexistente;

	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
			if ((**it).get_nome() == nome){
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
	string arq,NOME_CONC,NOME_P,SOBRENOME,CNPJ,MARCA,PRECO,CHASSI,MOTOR,MODELO,CARGA; 
	int motorr,modeloo,cargaa;
	string nomeConcAux,pNomeAux, sobrenomeAux,cnpjAux;
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
			getline	(arquivoE,NOME_CONC,';');
			getline	(arquivoE,NOME_P,';');
			getline	(arquivoE,SOBRENOME,';');
			getline	(arquivoE,CNPJ,';');
			getline	(arquivoE,MARCA,';');
			getline	(arquivoE,PRECO,';');
			getline	(arquivoE,CHASSI,';');
			getline	(arquivoE,MOTOR,';');
			getline	(arquivoE,MODELO,';');
			getline	(arquivoE,CARGA,'\n');
			
			if (CNPJ != "" && CNPJ != "CNPJ"){
				nomeConcAux = NOME_CONC;
				cnpjAux = CNPJ;
				pNomeAux = "";
				sobrenomeAux = "";
				break;		
			}
			else if(NOME_P != "" && NOME_P != "NOME" ){
				cnpjAux = "";
				nomeConcAux = NOME_CONC;
				pNomeAux = NOME_P;
				sobrenomeAux = SOBRENOME;
				break;		
			}
		}
		for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
			if ((**it).get_nome()== nomeConcAux){
				cout << endl << "Concessionaria ja cadastrado. Operacao CANCELADA!" << endl;
				return **it;
				arquivoE.close();
			}
		}
		if(arquivoE.is_open()){
	
		concessionaria *novaConc = new concessionaria(nomeConcAux,pNomeAux,sobrenomeAux,cnpjAux,listaConc_A,listaConc_M,listaConc_C);
		listaLoja.push_back(novaConc);		
	 	while(arquivoE.good()){
			getline	(arquivoE,NOME_CONC,';');
			getline	(arquivoE,NOME_P,';');
			getline	(arquivoE,SOBRENOME,';');
			getline	(arquivoE,CNPJ,';');
			getline	(arquivoE,MARCA,';');
			getline	(arquivoE,PRECO,';');
			getline	(arquivoE,CHASSI,';');
			getline	(arquivoE,MOTOR,';');
			getline	(arquivoE,MODELO,';');
			getline	(arquivoE,CARGA,'\n');
			
			if (CNPJ != "" && CNPJ != "CNPJ" && NOME_P != "" && NOME_P != "NOME" ){			
					concessionaria *novaConc = new concessionaria(nomeConcAux,pNomeAux,sobrenomeAux,cnpjAux,listaConc_A,listaConc_M,listaConc_C);
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
			arquivo << "NOME CONC;NOME;SOBRENOME;CNPJ;MARCA;PRECO;CHASSI;MOTOR;MODELO;CARGA"<< endl;
			
			string cnpjAux = (**it).get_cnpj();
			if ( cnpjAux == ""){	
				arquivo << nome <<";"<< (**it).get_primeiro_nome() <<";" << (**it).get_sobrenome()<<";" <<";;;;;;";
			}
			else{
				arquivo << nome <<";;;"<< cnpjAux <<";;;;;;";
			}
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
bool gerenciar::listarConcessionarias(){
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
			string cnpjAux = (**it).get_cnpj();
			cout << endl << " Concessionaria " << nome << endl<< endl;
			if ( cnpjAux == ""){
				cout << " Proprietario " << (**it).get_primeiro_nome() << " " << (**it).get_sobrenome() << endl;	
			}
			else{
				cout << endl << " CNJP " << (**it).get_cnpj() << endl;
			}
			cout << " Fronta total de Automoveis : " << (**it).getSizeLista_A() << endl;
			cout << " Fronta total de Moto       : " << (**it).getSizeLista_M() << endl;
			cout << " Fronta total de Caminhao   : " << (**it).getSizeLista_C() << endl;
			cout << " Total de Veiculos          : " << (**it).getSizeLista_A()+ (**it).getSizeLista_M() + (**it).getSizeLista_C() << endl;
			return true;
		}
	}
	cout << endl << "Concessionaria nao encontrada. Tente novamente." << endl;
	return false;	
}




