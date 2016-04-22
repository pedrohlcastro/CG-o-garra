#include <GL/glew.h>
#include <GL/freeglut.h>

#ifdef WIN32
    #include <SOIL.h>
#else
    #include <SOIL/SOIL.h>
#endif

#include <bits/stdc++.h>
#include "estruturas_basicas.h"

using namespace std;

int intImgLogo;

void desenhaCuboCustomizado(float fltSize,Cor corObjeto){
    glPushMatrix();
        glBegin(GL_QUADS);
            // front face
            glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
            glVertex3f(fltSize/2,fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
            glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
            // left face
            glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
            glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
            glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
            // back face
            glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
            glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
            glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
            glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
            glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
            // right face
            glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
            glVertex3f(fltSize/2,fltSize/2,fltSize/2);
            glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
            glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
            glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
            // top face
            glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
            glVertex3f(fltSize/2,fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
            glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
            // bottom face
            glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
            glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
            glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
        glEnd();
    glPopMatrix();
}

void desenhaMaquina(float fltSize,Cor corObjeto){
    glPushMatrix();
        //base da maquina
        glTranslated(0,-5,0);
        desenhaCuboCustomizado(5,corObjeto);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,5,0);
        desenhaCuboCustomizado(5,corObjeto);
    glPopMatrix();
    

}