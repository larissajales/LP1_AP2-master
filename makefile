CC = g++ #compilador

CPPFLAGS = -Wall -std=c++11 #flags

#executavel
AP2: veiculo.o moto.o caminhao.o automovel.o gerenciar.o concessionaria.o mainAP.o 
	@$(CC) $(CPPFLAGS) -Iinclude veiculo.o moto.o caminhao.o automovel.o gerenciar.o concessionaria.o mainAP.o  -o AP2											
		
	@mv *.o build/ #enviando os .o para pasta objects
	
# o -I include diz que a biblioteca está nessa pasta

veiculo.o: src/veiculo.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/veiculo.cpp
	@echo "Instalando veiculo..."

moto.o: src/moto.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/moto.cpp
	@echo "Instalando moto..."

caminhao.o: src/caminhao.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/caminhao.cpp
	@echo "Instalando caminhao..."

automovel.o: src/automovel.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/automovel.cpp
	@echo "Instalando automovel..."

gerenciar.o: src/gerenciar.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/gerenciar.cpp
	@echo "Instalando gerenciar..."

concessionaria.o: src/concessionaria.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/concessionaria.cpp
	@echo "Instalando concessionaria..."

mainAP.o: src/mainAP.cpp
	@$(CC) $(CPPFLAGS) -c -Iinclude src/mainAP.cpp
	@echo "Aguarde..."
	@echo "Pronto!!!\nPara mais informações digite o comando --> ./AP2\n"
clean:
	@rm -rf AP2
	@echo "Diretorio limpo"
