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
bool blnAbrir = false;

float intTamanhoDescida = 0;

Coordenadas crdEsfera;

void AtualizaCoordenadaEsfera(Coordenadas crdGarra){
    crdEsfera.fltX = crdGarra.fltX;
    crdEsfera.fltY = crdGarra.fltY;
    crdEsfera.fltZ = crdGarra.fltZ;

    crdEsfera.fltY -= 2.0 + (intTamanhoDescida/2);
}

void desenhaGarra(Garra grrGarra){
    //glClear (GL_COLOR_BUFFER_BIT);
    //Garra
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
        glTranslatef (grrGarra.crdGarra.fltX, grrGarra.crdGarra.fltY, grrGarra.crdGarra.fltZ);
        glRotatef ((GLfloat) anguloOmbro, 0.0, 0.0, 1.0);
        glRotatef ((GLfloat) anguloOmbro, 0.5, 0.0, 0.0);
        glPushMatrix();
            glColor3f(0.0,1.0,0.0);
            glutSolidCube (1.0);
        glPopMatrix();

        //Suporte
        glRotatef ((GLfloat) anguloSuporte, 0.0, 0.0, 1.0);
        glTranslatef (1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef (crdTamanhoSuporte.fltX + (intTamanhoDescida), crdTamanhoSuporte.fltY, crdTamanhoSuporte.fltZ);
            glutSolidCube (1.0);
        glPopMatrix();
        //Esfera
        glTranslatef (1.0 + (intTamanhoDescida/2), 0.0, 0.0);
        glPushMatrix();
            glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
            glutSolidSphere(0.4,200,200);
        glPopMatrix();
        glTranslatef (-(1.0 + (intTamanhoDescida/2)), 0.0, 0.0);
        glColor3f(1.0,1.0,1.0);

        //Garra Direita
        glColor3f(0.0,1.0,0.0);
        glPushMatrix();
            glTranslatef (crdGarrasEsquerdaDireita.fltX + (intTamanhoDescida/2), crdGarrasEsquerdaDireita.fltY, crdGarrasEsquerdaDireita.fltZ);

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
            glTranslatef (crdGarrasInferiorSuperior.fltX + (intTamanhoDescida/2), crdGarrasInferiorSuperior.fltY, crdGarrasInferiorSuperior.fltZ);
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
            glTranslatef (crdGarrasInferiorSuperior.fltX + (intTamanhoDescida/2), -crdGarrasInferiorSuperior.fltY, crdGarrasInferiorSuperior.fltZ);
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
            glTranslatef (crdGarrasEsquerdaDireita.fltX + (intTamanhoDescida/2), crdGarrasEsquerdaDireita.fltY, -crdGarrasEsquerdaDireita.fltZ);
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

    AtualizaCoordenadaEsfera(grrGarra.crdGarra);
}

bool HabilitarMovimento(){
    if(blnDescer && blnSubir && blnMovimentoEixoZ && blnMovimentoEixoX && blnFechar && blnAbrir){
        blnMovimentando = false;
        blnDescer = false;
        blnSubir = false;
        blnMovimentoEixoZ = false;
        blnMovimentoEixoX = false;
        blnFechar = false;
        blnAbrir = false;
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
    blnAbrir = false;
}


Garra MovimentaGarra(Garra grrGarra){
    if(grrGarra.crdGarra.fltX == -2)
        blnMovimentoEixoX = true;
    if(grrGarra.crdGarra.fltZ == -2)
        blnMovimentoEixoZ = true;
    if (grrGarra.intDireita == 30)
        blnFechar = true;
    if(!blnDescer && intTamanhoDescida == 3)
        blnDescer = true;


    if(!blnDescer)
        intTamanhoDescida++;
    else if(!blnFechar){
        grrGarra.intDireita = (grrGarra.intDireita + 5) % 360;
        grrGarra.intEsquerda = ((grrGarra.intEsquerda + 5) % 360);
        grrGarra.intInferior = (grrGarra.intInferior + 5) % 360;
        grrGarra.intSuperior = (grrGarra.intSuperior + 5) % 360;
    }
    else if(!blnSubir)
        intTamanhoDescida--;
    else if(!blnMovimentoEixoX)
        grrGarra.crdGarra.fltX--;
    else if(!blnMovimentoEixoZ)
        grrGarra.crdGarra.fltZ--;
    else {
        grrGarra.intDireita = (grrGarra.intDireita - 5) % 360;
        grrGarra.intEsquerda = ((grrGarra.intEsquerda - 5) % 360);
        grrGarra.intInferior = (grrGarra.intInferior - 5) % 360;
        grrGarra.intSuperior = (grrGarra.intSuperior - 5) % 360;
    }
    if(blnFechar && intTamanhoDescida == 0)
        blnSubir = true;
    if (blnDescer && grrGarra.intDireita == 0)
        blnAbrir = true;
    return grrGarra;
}

Coordenadas GetCoordenadaEsfera(){
    return crdEsfera;
}
