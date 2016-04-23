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

int setObjetosFundo(int intFase,float fltAreaCaixaVidro){
	FILE * fileCordenadas;
	int intTam;
	srand(time(0));
	float aux;
	if(intFase==1){
		#ifdef WIN32
            fileCordenadas=fopen("cord_Obj/cordenadas1.txt","r");
        #else
            fileCordenadas=fopen("../cord_Obj/cordenadas1.txt","r");
        #endif

		if(fileCordenadas==NULL){
			cout<<"ERRO ABRIR ARQUIVO"<<endl;
		}
		fscanf(fileCordenadas,"%d",&intTam);
		for(int i=0;i<intTam;i++){
			fscanf(fileCordenadas,"%f",&aux);
			objfVetorObjetos[i].crdObjetosFundo.fltX=aux;
			fscanf(fileCordenadas,"%f",&aux);
			objfVetorObjetos[i].crdObjetosFundo.fltY=aux;
			fscanf(fileCordenadas,"%f",&aux);
			objfVetorObjetos[i].crdObjetosFundo.fltZ=aux;

			int intTipoAux=rand()%4;
			objfVetorObjetos[i].intTipo=CUBO;
			objfVetorObjetos[i].fltTamanhoObjeto = 0.5;

			//esferas flutuando... parte a implmentar...
			/*if(intTipoAux%2==0){
				objfVetorObjetos[i].intTipo=CUBO;
				objfVetorObjetos[i].fltTamanhoObjeto = 0.5;
			}
			else{
				objfVetorObjetos[i].intTipo=ESFERA;
				objfVetorObjetos[i].fltTamanhoObjeto = 0.30;
			}*/
		}
	}
	fclose(fileCordenadas);
	return intTam;
}

void desenhaObjetosFundo(int intQtd){
	//cor provisoria
	float intX=1,intY=1;

	for(int i=0;i<intQtd;i++){
		glPushMatrix();
			glColor3f(intX,intY,1);
			float corDif[]={intX,intY,1,1};
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, corDif);
        	glTranslatef(objfVetorObjetos[i].crdObjetosFundo.fltX,objfVetorObjetos[i].crdObjetosFundo.fltY,objfVetorObjetos[i].crdObjetosFundo.fltZ);
        	if(objfVetorObjetos[i].intTipo==CUBO)
        		glutSolidCube(objfVetorObjetos[i].fltTamanhoObjeto);
        	if(objfVetorObjetos[i].intTipo==ESFERA)
        		glutSolidSphere(objfVetorObjetos[i].fltTamanhoObjeto,100,100);
		glPopMatrix();
		if(i%2==0)
			intX-=0.2;
		else
			intY-=0.2;
	}
}

void Colisao(Coordenadas crdEsfera, int intQtd){

    float fltDistanciaX;
    float fltRaio = 0.4;
    float fltTamanhoCubo = 0.5;
    bool blnRetorno = false;

    for(int i=0; i < intQtd; i++){
        fltDistanciaX = sqrt(pow(crdEsfera.fltX - objfVetorObjetos[i].crdObjetosFundo.fltX, 2) + pow(crdEsfera.fltY - objfVetorObjetos[i].crdObjetosFundo.fltY, 2) + pow(crdEsfera.fltZ - objfVetorObjetos[i].crdObjetosFundo.fltZ, 2));
        if (fltDistanciaX < (fltTamanhoCubo + fltRaio)) { blnRetorno = true; };
        if(blnRetorno){
            cout << "Colidiu" << endl;
        }

    }


}
