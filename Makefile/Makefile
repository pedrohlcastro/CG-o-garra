CC=g++
OPCOES_COMPILADOR=-I. -lSOIL -lGL -lGLU -lglut -lGLEW -lsfml-audio -lm
all:arquivos

arquivos: main.o skybox.o garra.o desenho.o objetos_fundo.o telasControle.o
	$(CC) main.o skybox.o garra.o desenho.o objetos_fundo.o telasControle.o -o executavel $(OPCOES_COMPILADOR)
	@echo "\nCRIADO COM SUCESSO UTILIZE MAKE RUN PARA RODAR\n"

main.o: ../main.cpp
	$(CC) -o main.o -c ../main.cpp $(OPCOES_COMPILADOR)

skybox.o: ../skybox.cpp
	$(CC) -o skybox.o -c ../skybox.cpp $(OPCOES_COMPILADOR)

garra.o: ../garra.cpp
	$(CC) -o garra.o -c ../garra.cpp $(OPCOES_COMPILADOR)

desenho.o: ../desenho.cpp
	$(CC) -o desenho.o -c ../desenho.cpp $(OPCOES_COMPILADOR)

objetos_fundo.o: ../objetos_fundo.cpp
	$(CC) -o objetos_fundo.o -c ../objetos_fundo.cpp $(OPCOES_COMPILADOR)

telasControle.o: ../telasControle.cpp
	$(CC) -o telasControle.o -c ../telasControle.cpp $(OPCOES_COMPILADOR)

run:
	./executavel

clean:
	rm -rf *o arquivos
	@echo "Arquivos .o deletados com suecesso\n"

install:
	sudo apt-get install build-essential
	sudo apt-get install freeglut3-dev
	sudo apt-get install libglew1.6-dev
	sudo apt-get install libsfml-dev
	sudo apt-get install libsoil-dev