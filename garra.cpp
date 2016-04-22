#include <GL/glew.h>
#include <GL/freeglut.h>

#ifdef WIN32
    #include <SOIL.h>
#else
    #include <SOIL/SOIL.h>
#endif

#include <bits/stdc++.h>
#include "estruturas_basicas.h"

int anguloOmbro = 270, anguloSuporte = 0;

Coordenadas crdGarrasEsquerdaDireita = {0.7, -0.09, 0.4};
Coordenadas crdGarrasInferiorSuperior = {0.7, 0.4, 0.0};
Coordenadas crdTamanhoGarra = {0.6, 0.2, 0.2};
Coordenadas crdTamanhoSuporte = {1.0, 1.0, 1.0};

bool blnDescer = false;
bool blnSubir = false;
bool blnMovimentoEixoZ = false;
bool blnMovimentoEixoX = false;
bool blnMovimentando = false;
bool blnFechar = false;

void desenhaGarra(Coordenadas crdGarra, Garra grrGarra){
    //glClear (GL_COLOR_BUFFER_BIT);
    //Garra
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
        glTranslatef (crdGarra.fltX, crdGarra.fltY, crdGarra.fltZ);
        glRotatef ((GLfloat) anguloOmbro, 0.0, 0.0, 1.0);
        glRotatef ((GLfloat) anguloOmbro, 0.5, 0.0, 0.0);
        glPushMatrix();
            glColor3f(0.0,1.0,0.0);
            glutWireCube (1.0);
        glPopMatrix();

        //Suporte
        glRotatef ((GLfloat) anguloSuporte, 0.0, 0.0, 1.0);
        glTranslatef (1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef (crdTamanhoSuporte.fltX, crdTamanhoSuporte.fltY, crdTamanhoSuporte.fltZ);
            glutWireCube (1.0);
        glPopMatrix();

        //Garra Direita
        glColor3f(0.0,1.0,0.0);
        glPushMatrix();
            glTranslatef (crdGarrasEsquerdaDireita.fltX, crdGarrasEsquerdaDireita.fltY, crdGarrasEsquerdaDireita.fltZ);
            glPushMatrix();
                glScalef (crdTamanhoGarra.fltX, crdTamanhoGarra.fltY, crdTamanhoGarra.fltZ);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intDireita, 0.0, 1.0, 0.0);
            glPushMatrix();
                glScalef (crdTamanhoGarra.fltX, crdTamanhoGarra.fltY, crdTamanhoGarra.fltZ);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intDireita, 0.0, 1.0, 0.0);
            glPushMatrix();
                glScalef (crdTamanhoGarra.fltX, crdTamanhoGarra.fltY, crdTamanhoGarra.fltZ);
                glutWireCube (0.8);
            glPopMatrix();
        glPopMatrix();


        //Garra Superior
        glPushMatrix();
            glTranslatef (crdGarrasInferiorSuperior.fltX, crdGarrasInferiorSuperior.fltY, crdGarrasInferiorSuperior.fltZ);
            glPushMatrix();
                glScalef (crdTamanhoGarra.fltX, crdTamanhoGarra.fltY, crdTamanhoGarra.fltZ);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intSuperior * -1, 0.0, 0.0, 1.0);
            glPushMatrix();
                glScalef (crdTamanhoGarra.fltX, crdTamanhoGarra.fltY, crdTamanhoGarra.fltZ);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intSuperior * -1, 0.0, 0.0, 1.0);
            glPushMatrix();
                glScalef (crdTamanhoGarra.fltX, crdTamanhoGarra.fltY, crdTamanhoGarra.fltZ);
                glutWireCube (0.8);
            glPopMatrix();
        glPopMatrix();

        //Garra Inferior
        glPushMatrix();
            glTranslatef (crdGarrasInferiorSuperior.fltX, -crdGarrasInferiorSuperior.fltY, crdGarrasInferiorSuperior.fltZ);
            glPushMatrix();
                glScalef (crdTamanhoGarra.fltX, crdTamanhoGarra.fltY, crdTamanhoGarra.fltZ);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intInferior, 0.0, 0.0, 1.0);
            glPushMatrix();
                glScalef (crdTamanhoGarra.fltX, crdTamanhoGarra.fltY, crdTamanhoGarra.fltZ);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intInferior, 0.0, 0.0, 1.0);
            glPushMatrix();
                glScalef (crdTamanhoGarra.fltX, crdTamanhoGarra.fltY, crdTamanhoGarra.fltZ);
                glutWireCube (0.8);
            glPopMatrix();
        glPopMatrix();


        //Garra Esquerda
        glPushMatrix();
            glTranslatef (crdGarrasEsquerdaDireita.fltX, crdGarrasEsquerdaDireita.fltY, -crdGarrasEsquerdaDireita.fltZ);
            glPushMatrix();
                glScalef (crdTamanhoGarra.fltX, crdTamanhoGarra.fltY, crdTamanhoGarra.fltZ);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intEsquerda * -1, 0.0, 1.0, 0.0);
            glPushMatrix();
                glScalef (crdTamanhoGarra.fltX, crdTamanhoGarra.fltY, crdTamanhoGarra.fltZ);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intEsquerda * -1, 0.0, 1.0, 0.0);
            glPushMatrix();
                glScalef (crdTamanhoGarra.fltX, crdTamanhoGarra.fltY, crdTamanhoGarra.fltZ);
                glutWireCube (0.8);
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();
}

bool HabilitarMovimento(){
    if(blnDescer && blnSubir && blnMovimentoEixoZ && blnMovimentoEixoX && blnFechar){
        blnMovimentando = false;
        blnDescer = false;
        blnSubir = false;
        blnMovimentoEixoZ = false;
        blnMovimentoEixoX = false;
        blnFechar = false;
    }

    return !blnMovimentando;

}

void IniciarMovimentacaoAutomatico(){
    blnMovimentando = true;
    blnDescer = false;
    blnSubir = false;
    blnMovimentoEixoZ = false;
    blnMovimentoEixoX = false;
    blnFechar = false;
}

Coordenadas MovimentaGarra(Coordenadas crdGarra, Garra grrGarra){
    blnDescer = true;
    blnSubir = true;
    if(crdGarra.fltX == -2)
        blnMovimentoEixoX = true;
    if(crdGarra.fltZ == -2)
        blnMovimentoEixoZ = true;
    if (grrGarra.intDireita == 30)
        blnFechar = true;

    /*if(!blnFechar){
        grrGarra.intDireita = (grrGarra.intDireita + 5) % 360;
        grrGarra.intEsquerda = ((grrGarra.intEsquerda + 5) % 360);
        grrGarra.intInferior = (grrGarra.intInferior + 5) % 360;
        grrGarra.intSuperior = (grrGarra.intSuperior + 5) % 360;
    }
    else*/ if(!blnMovimentoEixoX)
        crdGarra.fltX--;
    else if(!blnMovimentoEixoZ)
        crdGarra.fltZ--;
    return crdGarra;
}
