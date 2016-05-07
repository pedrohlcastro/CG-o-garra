#include <GL/glew.h>
#include <GL/freeglut.h>
#ifdef WIN32
    #include <SOIL.h>
#else
    #include <SOIL/SOIL.h>
#endif
#include <stdio.h>
#include <iostream>
#include "estruturas_basicas.h"
#include "objetos_fundo.h"
#include <time.h>
#include<math.h>
using namespace std;

objetosFundo objfVetorObjetos[1000];
int intIndexObjetoColisao=-1;

void setBuraco(int intIndex){
    objfVetorObjetos[intIndex].crdObjetosFundo.fltX = -1.99;
    objfVetorObjetos[intIndex].crdObjetosFundo.fltY = -2.99;
    objfVetorObjetos[intIndex].crdObjetosFundo.fltZ = -2;
    objfVetorObjetos[intIndex].intTipo = CUBO;
    objfVetorObjetos[intIndex].fltTamanhoObjeto = 1;
}
//Cria os objetos baseado em informacoes contidas em um arquivo texto
int setObjetosFundo(int intFase, float fltAreaCaixaVidro){
	FILE * fileCordenadas;
	float fltAuxiliar;
	int intTipoAux, intAuxiliar, intTam;

	srand(time(0));
	if(intFase == 1){
		#ifdef WIN32
            fileCordenadas=fopen("cord_Obj/cordenadas1.txt","r");
        #else
            fileCordenadas=fopen("../cord_Obj/cordenadas1.txt","r");
        #endif

		if(fileCordenadas==NULL)
			cout<<"ERRO ABRIR ARQUIVO"<<endl;

		fscanf(fileCordenadas,"%d",&intTam);

		for(intAuxiliar = 0 ;intAuxiliar < intTam ; intAuxiliar++){
			fscanf(fileCordenadas,"%f",&fltAuxiliar);
			objfVetorObjetos[intAuxiliar].crdObjetosFundo.fltX = fltAuxiliar;
			fscanf(fileCordenadas,"%f",&fltAuxiliar);
			objfVetorObjetos[intAuxiliar].crdObjetosFundo.fltY = fltAuxiliar;
			fscanf(fileCordenadas,"%f",&fltAuxiliar);
			objfVetorObjetos[intAuxiliar].crdObjetosFundo.fltZ = fltAuxiliar;
            //Forma aleatoria de definir o tipo do objeto(cubo, esfera)
			intTipoAux=rand()%4;
			if(intTipoAux%2==0){
				objfVetorObjetos[intAuxiliar].intTipo=CUBO;
				objfVetorObjetos[intAuxiliar].fltTamanhoObjeto = 0.5;
			}
			else{
				objfVetorObjetos[intAuxiliar].intTipo=ESFERA;
				objfVetorObjetos[intAuxiliar].fltTamanhoObjeto = 0.30;
			}
		}
        fclose(fileCordenadas);
	}

	setBuraco(intTam);

	return intTam; //retorna a quantidade de objetos criados
}

void desenhaObjetosFundo(int intQtd){
	//cor provisoria
	Coordenadas crdCor = {1,1,1};
	int intAuxiliar;

	for(intAuxiliar = 0; intAuxiliar < intQtd +1 ; intAuxiliar++){
		glPushMatrix();
			glColor3f(crdCor.fltX,crdCor.fltY,crdCor.fltZ);
			float corDif[] = {crdCor.fltX, crdCor.fltY, crdCor.fltZ, 1};
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, corDif);
        	glTranslatef(objfVetorObjetos[intAuxiliar].crdObjetosFundo.fltX, objfVetorObjetos[intAuxiliar].crdObjetosFundo.fltY, objfVetorObjetos[intAuxiliar].crdObjetosFundo.fltZ);
        	if(objfVetorObjetos[intAuxiliar].intTipo==CUBO)
        		glutSolidCube(objfVetorObjetos[intAuxiliar].fltTamanhoObjeto);
        	if(objfVetorObjetos[intAuxiliar].intTipo==ESFERA)
        		glutSolidSphere(objfVetorObjetos[intAuxiliar].fltTamanhoObjeto,100,100);
		glPopMatrix();
        if(intAuxiliar == intQtd - 1){
            crdCor.fltX = 0;
            crdCor.fltY = 0;
            crdCor.fltZ = 0;
        }
		else if(intAuxiliar%2==0)
			crdCor.fltX-=0.2;
		else
			crdCor.fltY-=0.2;
	}
}
//Funcao que determina a colisao entre os objetos e a garra. Quando acontece a colisao, a funcao retorna o index do objeto. Caso contrario, retorna -1
int Colisao(Coordenadas crdEsfera, int intQtd,int *intQtdPedente, float fltRaio){
    float fltDistancia;
    int intIndexRetorno = -1, intAuxiliar = 0;

    for(intAuxiliar = 0; intAuxiliar < intQtd; intAuxiliar++){
        //Distancia entre o centro da esfera da garra e o centro do objeto
        fltDistancia = sqrt(pow(crdEsfera.fltX - objfVetorObjetos[intAuxiliar].crdObjetosFundo.fltX, 2) + pow(crdEsfera.fltY - objfVetorObjetos[intAuxiliar].crdObjetosFundo.fltY, 2) + pow(crdEsfera.fltZ - objfVetorObjetos[intAuxiliar].crdObjetosFundo.fltZ, 2));
        if(objfVetorObjetos[intAuxiliar].intTipo == CUBO){
            if (fltDistancia < (objfVetorObjetos[intAuxiliar].fltTamanhoObjeto + fltRaio))
                return intAuxiliar;
        }
        else{
            if (fltDistancia < ((objfVetorObjetos[intAuxiliar].fltTamanhoObjeto + 0.2) + fltRaio))
                return intAuxiliar;
        }

    }

    return intAuxiliar;
}

//Funcoes que modificam as coordenadas dos objetos
void LevantaObjeto(int intIndexObjeto){
    intIndexObjetoColisao = intIndexObjeto;
    if(objfVetorObjetos[intIndexObjeto].crdObjetosFundo.fltY < -1)
        objfVetorObjetos[intIndexObjeto].crdObjetosFundo.fltY++;
}

void MovimentaObjetoEixoX(int intIndexObjeto){
    objfVetorObjetos[intIndexObjeto].crdObjetosFundo.fltX--;
}

void MovimentaObjetoEixoZ(int intIndexObjeto){
    objfVetorObjetos[intIndexObjeto].crdObjetosFundo.fltZ--;
}
//Funcao para descer o objeto agarrado, retorna true quando o objeto sai da visao do usuario
bool DesceObjeto(){
    bool blnRetorno = false;
    objfVetorObjetos[intIndexObjetoColisao].crdObjetosFundo.fltY--;
    if(objfVetorObjetos[intIndexObjetoColisao].crdObjetosFundo.fltY < -3)
        blnRetorno = true;

    return blnRetorno;
}
