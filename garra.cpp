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

int anguloOmbro = 270, anguloSuporte = 0;

Coordenadas crdGarrasEsquerdaDireita = {0.7, -0.09, 0.4};
Coordenadas crdGarrasInferiorSuperior = {0.7, 0.4, 0.0};
Coordenadas crdTamanhoGarra = {0.6, 0.2, 0.2};
Coordenadas crdTamanhoSuporte = {1.0, 1.0, 1.0};
Coordenadas crdEsfera;
float fltTamanhoDescida = 0, fltRaioEsfera = 0.25;

//Variaveis booleanas do movimento automatico da garra
bool blnDescer = false;
bool blnSubir = false;
bool blnMovimentoEixoZ = false;
bool blnMovimentoEixoX = false;
bool blnMovimentando = false;
bool blnFechar = false;
bool blnAbrir = false;
bool blnDescidaObjeto = false;

//Funcoes GET
Coordenadas GetCoordenadaEsfera(){
    return crdEsfera;
}

float GetRaioEsfera(){
    return fltRaioEsfera;
}

//Retorna o valor das variaveis booleanas para o estado inicial.
void RetornaVariaveisValorInicial(){
    blnMovimentando = true;
    blnDescer = false;
    blnSubir = false;
    blnMovimentoEixoZ = false;
    blnMovimentoEixoX = false;
    blnFechar = false;
    blnAbrir = false;
    blnDescidaObjeto = false;
}

void AtualizaCoordenadaEsfera(Coordenadas crdGarra){
    crdEsfera.fltX = crdGarra.fltX;
    crdEsfera.fltY = crdGarra.fltY;
    crdEsfera.fltZ = crdGarra.fltZ;

    crdEsfera.fltY -= 2.0 + (fltTamanhoDescida/2);
}

//Procedimento de desenho das falanges
void desenhaFalange(){
    glPushMatrix();
        glScalef (crdTamanhoGarra.fltX, crdTamanhoGarra.fltY, crdTamanhoGarra.fltZ);
        glutWireCube (0.8);
    glPopMatrix();
}

//Procedimento de desenho da garra
void desenhaGarra(Garra grrGarra){
    //Garra
    float fltLuzDif[] = {1, 1, 1, 0};
    float fltLuzEsp[] = {1, 1, 1, 0};
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
        glTranslatef (grrGarra.crdGarra.fltX, grrGarra.crdGarra.fltY, grrGarra.crdGarra.fltZ);
        glRotatef ((GLfloat) anguloOmbro, 0.0, 0.0, 1.0);
        glRotatef ((GLfloat) anguloOmbro, 0.5, 0.0, 0.0);
        glPushMatrix();
            glColor3f(1.0,1.0,1.0);
            glutSolidCube (1.0);
        glPopMatrix();

        //Suporte
        glRotatef ((GLfloat) anguloSuporte, 0.0, 0.0, 1.0);
        glTranslatef (1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef (crdTamanhoSuporte.fltX + (fltTamanhoDescida), crdTamanhoSuporte.fltY, crdTamanhoSuporte.fltZ);
            glutSolidCube (1.0);
        glPopMatrix();
        //Esfera
        glTranslatef (1.0 + (fltTamanhoDescida/2), 0.0, 0.0);
        glPushMatrix();
            glColor4f(1.0,1.0,1.0,0.0);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, fltLuzDif);
            glutSolidSphere(fltRaioEsfera, 200, 200);
        glPopMatrix();
        fltLuzDif[0]=1; fltLuzDif[1]=1; fltLuzDif[2]=1; fltLuzDif[3]=1;
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, fltLuzDif);
        glTranslatef (-(1.0 + (fltTamanhoDescida/2)), 0.0, 0.0);
        glColor3f(1.0,1.0,1.0);

        //Garra Direita
        glColor3f(1.0,1.0,1.0);
        glPushMatrix();
            glTranslatef (crdGarrasEsquerdaDireita.fltX + (fltTamanhoDescida/2), crdGarrasEsquerdaDireita.fltY, crdGarrasEsquerdaDireita.fltZ);

            desenhaFalange();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intDireita, 0.0, 1.0, 0.0);
            desenhaFalange();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intDireita, 0.0, 1.0, 0.0);
            desenhaFalange();
        glPopMatrix();

        //Garra Superior
        glPushMatrix();
            glTranslatef (crdGarrasInferiorSuperior.fltX + (fltTamanhoDescida/2), crdGarrasInferiorSuperior.fltY, crdGarrasInferiorSuperior.fltZ);
            desenhaFalange();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intSuperior * -1, 0.0, 0.0, 1.0);
            desenhaFalange();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intSuperior * -1, 0.0, 0.0, 1.0);
            desenhaFalange();
        glPopMatrix();

        //Garra Inferior
        glPushMatrix();
            glTranslatef (crdGarrasInferiorSuperior.fltX + (fltTamanhoDescida/2), -crdGarrasInferiorSuperior.fltY, crdGarrasInferiorSuperior.fltZ);
            desenhaFalange();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intInferior, 0.0, 0.0, 1.0);
            desenhaFalange();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intInferior, 0.0, 0.0, 1.0);
            desenhaFalange();
        glPopMatrix();


        //Garra Esquerda
        glPushMatrix();
            glTranslatef (crdGarrasEsquerdaDireita.fltX + (fltTamanhoDescida/2), crdGarrasEsquerdaDireita.fltY, -crdGarrasEsquerdaDireita.fltZ);
            desenhaFalange();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intEsquerda * -1, 0.0, 1.0, 0.0);
            desenhaFalange();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intEsquerda * -1, 0.0, 1.0, 0.0);
            desenhaFalange();
        glPopMatrix();

    glPopMatrix();

    AtualizaCoordenadaEsfera(grrGarra.crdGarra);
}

//Funcoes de movimentacao
//Destrava a movimentacao da garra para o usuario
bool HabilitarMovimento(){
    if(blnDescer && blnSubir && blnMovimentoEixoZ && blnMovimentoEixoX && blnFechar && blnAbrir && blnDescidaObjeto){
        RetornaVariaveisValorInicial();
        blnMovimentando = false;
    }

    return !blnMovimentando;
}

void IniciarMovimentacaoAutomatico(){
    RetornaVariaveisValorInicial();
}

//Funcao que realiza o movimento automatico da garra
Garra MovimentaGarra(Garra grrGarra, int intIndexObjeto){
    if(grrGarra.crdGarra.fltX == -2)
        blnMovimentoEixoX = true;
    if(grrGarra.crdGarra.fltZ == -2)
        blnMovimentoEixoZ = true;
    if (grrGarra.intDireita == 30)
        blnFechar = true;
    if(!blnDescer && fltTamanhoDescida == 3)
        blnDescer = true;

    if(!blnDescer)
        fltTamanhoDescida++;
    else if(!blnFechar){
        grrGarra.intDireita = (grrGarra.intDireita + 5) % 360;
        grrGarra.intEsquerda = ((grrGarra.intEsquerda + 5) % 360);
        grrGarra.intInferior = (grrGarra.intInferior + 5) % 360;
        grrGarra.intSuperior = (grrGarra.intSuperior + 5) % 360;
    }
    else if(!blnSubir){
        fltTamanhoDescida--;
        if(intIndexObjeto != -1)
            LevantaObjeto(intIndexObjeto);
    }
    else if(!blnMovimentoEixoX){
        grrGarra.crdGarra.fltX--;
        if(intIndexObjeto != -1)
            MovimentaObjetoEixoX(intIndexObjeto);
    }
    else if(!blnMovimentoEixoZ){
        grrGarra.crdGarra.fltZ--;
        if(intIndexObjeto != -1)
            MovimentaObjetoEixoZ(intIndexObjeto);
    }
    else if(!blnAbrir) {
        grrGarra.intDireita = (grrGarra.intDireita - 5) % 360;
        grrGarra.intEsquerda = ((grrGarra.intEsquerda - 5) % 360);
        grrGarra.intInferior = (grrGarra.intInferior - 5) % 360;
        grrGarra.intSuperior = (grrGarra.intSuperior - 5) % 360;
    }
    else
        blnDescidaObjeto = DesceObjeto();

    if(blnFechar && fltTamanhoDescida == 0)
        blnSubir = true;
    if (blnDescer && grrGarra.intDireita == 0)
        blnAbrir = true;

    return grrGarra;
}
