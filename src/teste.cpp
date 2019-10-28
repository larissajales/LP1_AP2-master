#include <iostream>
#include <ctime>


using namespace std;

string retonro();

string dataa;
void setData(string data_);

int main()
{	
	
	cout << retonro();
	cout << dataa<< "aqui";
  return 0;
}
void setData(string data_){
	dataa = data_;
}

string retonro(){
	string data;
  	time_t now = time(0);
	data = ctime(&now);
	string aux;
		for (int i = 0; i <data.size() -1; i++){
		aux += data[i];
	}
	data = aux;
	setData(aux);
	return aux;
}
