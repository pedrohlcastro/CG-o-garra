#include <GL/glew.h>
#include <GL/freeglut.h>
#ifdef WIN32
    #include <SOIL.h>
#else
    #include <SOIL/SOIL.h>
#endif
#include <bits/stdc++.h>
#include "estruturas_basicas.h"
#include "objetos_fundo.h"

using namespace std;

objetosFundo objfVetorObjetos[1000];

void setObjetosFundo(int intQtd,float fltAreaCaixaVidro){
	float fltTamMax=(float)fltAreaCaixaVidro/intQtd;
	srand(time(0));
	int tmp=(int)fltAreaCaixaVidro;

	for(int i=0;i<intQtd;i++){
		objfVetorObjetos[i].crdObjetosFundo.fltX = fltTamMax+rand()%tmp;
		if(objfVetorObjetos[i].crdObjetosFundo.fltX>(fltAreaCaixaVidro/2)){
			objfVetorObjetos[i].crdObjetosFundo.fltX-=(fltAreaCaixaVidro-fltTamMax);
		}
		cout<<objfVetorObjetos[i].crdObjetosFundo.fltX<<",";
		objfVetorObjetos[i].fltTamanhoObjeto = 0.5;

		objfVetorObjetos[i].crdObjetosFundo.fltY = -2.5+objfVetorObjetos[i].fltTamanhoObjeto;
		cout<<objfVetorObjetos[i].crdObjetosFundo.fltY<<",";


		objfVetorObjetos[i].crdObjetosFundo.fltZ = fltTamMax+rand()%tmp;
		if(objfVetorObjetos[i].crdObjetosFundo.fltZ>(fltAreaCaixaVidro/2)){
			objfVetorObjetos[i].crdObjetosFundo.fltZ-=(fltAreaCaixaVidro-fltTamMax);
		}
		cout<<objfVetorObjetos[i].crdObjetosFundo.fltZ<<endl;


		objfVetorObjetos[i].intTipo=CUBO;
		
		
	}
}

void desenhaObjetosFundo(int intQtd){	
	float x=1,y=1;
	for(int i=0;i<intQtd;i++){
		glPushMatrix();
			glColor3f(x,y,1);
        	glTranslatef(objfVetorObjetos[i].crdObjetosFundo.fltX,objfVetorObjetos[i].crdObjetosFundo.fltY,objfVetorObjetos[i].crdObjetosFundo.fltZ);
        	glutSolidCube(objfVetorObjetos[i].fltTamanhoObjeto);
		glPopMatrix();
		if(i%2==0)
			x-=0.2;
		else
			y-=0.2;
	}
}