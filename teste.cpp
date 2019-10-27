#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
	string arq,NOME,CNPJ,MARCA,PRECO,CHASSI,MOTOR,MODELO,CARGA; 


	string quebra;
	cout << "Informe o nome do arquivo: (INCLUIR .CSV)";
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
			
			if (CNPJ != ""&&CNPJ != "CNPJ"){
				int cnpk = stoi(string (CNPJ));
				cnpk = cnpk + 1;
				cout <<"AQUI  "<<cnpk<<endl;
			}
			cout <<NOME<<" "<<CNPJ<<" "<<MARCA<<" "<<PRECO<<" "<<CHASSI<<" "<<MOTOR<<" "<<MODELO<<" "<<CARGA<<endl;
		}
					
	}
	else{
		cout << "Erro ao abrir arquivo. Verifique se o nome esta correto. "<< endl;
		return 0;		
	}
}

