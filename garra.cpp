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

void desenhaGarra(Coordenadas crdGarra, Garra grrGarra){
    //glClear (GL_COLOR_BUFFER_BIT);
    //Garra
    glPushMatrix();
        glTranslatef (crdGarra.fltX, crdGarra.fltY, crdGarra.fltZ);
        glRotatef ((GLfloat) anguloOmbro, 0.0, 0.0, 1.0);
        glRotatef ((GLfloat) anguloOmbro, 0.5, 0.0, 0.0);
        glTranslatef (0.0, 0.0, 0.0);
        glPushMatrix();
            glColor3f(1.0,1.0,1.0);
            glScalef (1.0, 1.0, 1.0);
            glutWireCube (1.0);
        glPopMatrix();

        //Suporte
        glColor3f(0.0,1.0,0.0);
        glTranslatef (0.0, 0.0, 0.0);
        glRotatef ((GLfloat) anguloSuporte, 0.0, 0.0, 1.0);
        glTranslatef (1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef (1.0, 1.0, 1.0);
            glutWireCube (1.0);
        glPopMatrix();

        //Garra Direita
        glColor3f(1.0,1.0,1.0);
        glPushMatrix();
            glTranslatef (0.7, -0.09, 0.0);
            glRotatef (0.0, 0.0, 0.0, 0.0);
            glTranslatef (0.0, 0.0, 0.4);
            glPushMatrix();
                glScalef (0.6, 0.2, 0.2);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intDireita, 0.0, 1.0, 0.0);
            glTranslatef (0.0, 0.0, 0.0);
            glPushMatrix();
                glScalef (0.6, 0.2, 0.2);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intDireita, 0.0, 1.0, 0.0);
            glTranslatef (0.0, 0.0, 0.0);
            glPushMatrix();
                glScalef (0.6, 0.2, 0.2);
                glutWireCube (0.8);
            glPopMatrix();
        glPopMatrix();


        //Garra Superior
        glPushMatrix();
            glTranslatef (0.7, 0.4, 0.0);
            glRotatef (0.0, 0.0, 0.0, 0.0);
            glTranslatef (0.0, 0.0, 0.0);
            glPushMatrix();
                glScalef (0.6, 0.2, 0.2);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intSuperior * -1, 0.0, 0.0, 1.0);
            glTranslatef (0.0, 0.0, 0.0);
            glPushMatrix();
                glScalef (0.6, 0.2, 0.2);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intSuperior * -1, 0.0, 0.0, 1.0);
            glTranslatef (0.0, 0.0, 0.0);
            glPushMatrix();
                glScalef (0.6, 0.2, 0.2);
                glutWireCube (0.8);
            glPopMatrix();
        glPopMatrix();

        //Garra Inferior
        glPushMatrix();
            glTranslatef (0.7, -0.4, 0.0);
            glRotatef (0.0, 0.0, 0.0, 0.0);
            glTranslatef (0.0, 0.0, 0.0);
            glPushMatrix();
                glScalef (0.6, 0.2, 0.2);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intInferior, 0.0, 0.0, 1.0);
            glTranslatef (0.0, 0.0, 0.0);
            glPushMatrix();
                glScalef (0.6, 0.2, 0.2);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) grrGarra.intInferior, 0.0, 0.0, 1.0);
            glTranslatef (0.0, 0.0, 0.0);
            glPushMatrix();
                glScalef (0.6, 0.2, 0.2);
                glutWireCube (0.8);
            glPopMatrix();
        glPopMatrix();


        //Garra Esquerda
        glPushMatrix();
            glTranslatef (0.7, -0.05, 0.0);
            glRotatef (0.0, 0.0, 0.0, 0.0);
            glTranslatef (0.0, 0.0, -0.4);
            glPushMatrix();
                glScalef (0.6, 0.2, 0.2);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.1, 0.0);
            glRotatef ((GLfloat) grrGarra.intEsquerda * -1, 0.0, 1.0, 0.0);
            glTranslatef (0.0, -0.1,  0.0);
            glPushMatrix();
                glScalef (0.6, 0.2, 0.2);
                glutWireCube (0.8);
            glPopMatrix();

            glTranslatef (0.5, 0.1, 0.0);
            glRotatef ((GLfloat) grrGarra.intEsquerda * -1, 0.0, 1.0, 0.0);
            glTranslatef (0.0, -0.1,  0.0);
            glPushMatrix();
                glScalef (0.6, 0.2, 0.2);
                glutWireCube (0.8);
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();
}
