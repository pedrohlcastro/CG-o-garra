# CG-o-garra
TP02 Computação Gráfica 2016/01 CEFET-MG</br></br>
Durante uma missão espacial SUPER-SECRETA da NASA um grupo de astronautas foram atacados por Aliens na Lua...
O suprimento de Oxigênio deles esta acabando e a única esperança é conseguir as 5 capsulas faltantes no macabro jogo inventado pelos Aliens: O garra, mas como os Aliens queriam demostrar sua superioridade utilizaram uma mão de um astronauta como garra e limitaram o tempo de uso da garra...
SEU OBJETIVO É SIMPLES SALVE OS ASTRONAUTAS.

<h2>SISTEMAS SUPORTADOS: WINDOWS E LINUX</h2>

<img align="center" src="https://github.com/pedrohlcastro/CG-o-garra/blob/master/screenshots/img1.png?raw=true" width="250" height="300"/>
<img align="center" src="https://github.com/pedrohlcastro/CG-o-garra/blob/master/screenshots/img2.png?raw=true" width="250" height="300"/>
<img align="center" src="https://github.com/pedrohlcastro/CG-o-garra/blob/master/screenshots/im3.png?raw=true" width="250" height="300"/>

<h2>BLIBLIOTECAS E COMO RODAR EM LINUX:</h2>

<h4>COMPILANDO E RODANDO (LINUX):</h4>

FORAM USADAS AS BIBLIOTECAS GLEW,FREEGLUT,SOIL,SFML(AUDIO).
<h4>PARA ADQUIRIR AS BIBLIOTECAS (LINUX):</h4>
	
	sudo apt-get install build-essential
	sudo apt-get install freeglut3-dev
	sudo apt-get install libglew1.6-dev
	sudo apt-get install libsfml-dev
	sudo apt-get install libsoil-dev

OU USE 

	make install -->instala todas bibliotecas acima

PARA RODAR O JOGO EM LINUX BASTA SEGUIR OS SEGUINTE PASSOS:
	
	1- sudo apt-get install git
	2- git clone https://github.com/pedrohlcastro/CG-fuga-corrupta.git
	3- cd CG-o-garra/
	4- cd Makefile/
	5- make
	6- make run

CASO DESEJE COMPILAR O PROGAMA TAMBÉM USE OS COMANDOS DENTRO DA PASTA Makefile/:

	1- make all    --> compila o código
	2- make clean  --> limpa arquivos .o
	3- make run    --> roda o jogo

<h2>BLIBLIOTECAS E COMO RODAR EM WINDOWS:</h2>

<h4>COMPILANDO E RODANDO (WINDOWS):</h4>

FORAM USADAS AS BIBLIOTECAS GLEW,FREEGLUT,SOIL,SFML(AUDIO).
<h4>PARA ADQUIRIR AS BIBLIOTECAS (WINDOWS):</h4>
	
	ACESSE O SITE --> opengl.meteor.com

PARA RODAR O JOGO EM WINDOWS BASTA SEGUIR OS SEGUINTE PASSOS:
	
	1- INSTALAR O CODEBLOCKS
	2- BAIXE O REPOSITORIO: https://github.com/pedrohlcastro/CG-fuga-corrupta.git
	3- ENTRE NA PASTA DO CG-o-garra/
	4- ENTRE NA PASTA CodeBlocks/
	5- ABRA O ARQUIVO .cbp
	6- COMPILE E RODA APERTANDO F9

<h2>COMO JOGAR:</h2>
FUNCIONALIDADES:
	<p>USE <kbd>←</kbd><kbd>↑</kbd><kbd>→</kbd><kbd>↓</kbd> NO TECLADO PARA SE NAVEGAR NOS MENUS.</p>
	<p>USE <kbd>←</kbd><kbd>↑</kbd><kbd>→</kbd><kbd>↓</kbd> PARA MOVER A GARRA E <kbd>Backspace</kbd> PARA TENTAR PEGAR</p>
	<p>USE <kbd>A</kbd><kbd>W</kbd><kbd>D</kbd><kbd>S</kbd> PARA MOVER A CAMERA</p>
	<p>USE <kbd>Z</kbd><kbd>X</kbd> PARA ABRIR E FECHAR A GARRA</p>
	<p>O MOUSE PODE SER USADO PARA MOVIMENTAR SUTILMETE A CAMERA</p>
	<p><kbd>ESC</kbd> PARA SAIR DO JOGO</p>
	<p><kbd>P</kbd> VISAO PANORAMICA</p>

<h2>CREDITOS:</h2>
FEITO POR GUSTAVO MARQUES E PEDRO HENRIQUE LOPES PARA A DISCIPLINA DE COMPUTAÇÃO GRÁFICA 2016/01.
ALGUMAS IMAGENS E MÚSICAS FORAM RETIRADAS DO GOOGLE.
DEMO: https://youtu.be/VJ-Rr7Vf_N8
