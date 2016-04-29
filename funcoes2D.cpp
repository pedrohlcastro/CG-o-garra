#include <GL/glew.h>
#include <GL/freeglut.h>
#ifdef WIN32
    #include <SOIL.h>
#else
    #include <SOIL/SOIL.h>
#endif
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include "estruturas_basicas.h"

using namespace std;

int intImgCapacete=-1;

void desenhaTempo(int intTempo){
    GLint intAux=-250;
    GLint intExtremo_da_tela=-250;
    //cor azul
    glColor3f(0.0859375,0.31640625,0.71875);
    for(int i=0;i<intTempo;i++){
        glPushMatrix();
            glTranslatef(intExtremo_da_tela , intAux, 0);
            glBegin(GL_POLYGON);
                glVertex2f(0,0);
                glVertex2f(30,0);
                glVertex2f(30,30);
                glVertex2f(0,30);           
            glEnd();
        glPopMatrix();
        intAux+=10;
    }
}

void desenhaQtdObjetosPedentes(int intQtdPedente){
    GLint intAux=-250;
    for(int i=0;i<intQtdPedente;i++){
        glPushMatrix();
            glColor4f(1,1,1,1);
            glTranslatef(-200,intAux,0);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,intImgCapacete);
            glBegin(GL_POLYGON);
                glTexCoord2f(0, 0);     glVertex2f(0,0);
                glTexCoord2f(1, 0);     glVertex2f(30,0);
                glTexCoord2f(1, 1);     glVertex2f(30,30);
                glTexCoord2f(0, 1);     glVertex2f(0,30);           
            glEnd();
            glDisable(GL_TEXTURE_2D);
        glPopMatrix();
        intAux+=32;
    }
}

void DesenhaParte2D(int intTempo,Coordenadas crdCamera,int intQtdPedente){
    //carrega modelo de visao 2d
    glMatrixMode (GL_PROJECTION);
    glPushMatrix();
        glLoadIdentity();
        gluOrtho2D (-250, 250, -250, 250);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glLoadIdentity();
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_CULL_FACE);
        glDisable(GL_LIGHTING);
        //desenha 2D
        if(intImgCapacete==-1){
            intImgCapacete= SOIL_load_OGL_texture(
                #ifdef WIN32
                    "img/cpc.png",
                #else
                    "../img/cpc.png",
                #endif
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_INVERT_Y
            );
            if (intImgCapacete == 0 ) {
                printf("Erro carregando textura: '%s'\n", SOIL_last_result());
            }
        }
        desenhaTempo(intTempo);
        desenhaQtdObjetosPedentes(intQtdPedente);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    //recoloca camera na matriz MODELVIEW
    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef (0.0, 0.0, -5.0);
        gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
 
}

