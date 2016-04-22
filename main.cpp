#include <GL/glew.h>
#include <GL/freeglut.h>
#ifdef WIN32
    #include <SOIL.h>
#else
    #include <SOIL/SOIL.h>
#endif
#include <bits/stdc++.h>
#include "skybox.h"
#include "estruturas_basicas.h"
#include "garra.h"
#include "desenho.h"

using namespace std;

Coordenadas crdCamera, crdGarra;
Garra grrGarra;
Cor corObjeto;

void Inicializa(){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
    crdCamera = {0, 1, 3};
    crdGarra = {-2.0, 2.0, 0.0};
    grrGarra = {0, 0, 0 ,0};
    corObjeto = {1, 1, 1, 0.3};
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
    gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);

}

void Desenha(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);

    desenhaSkybox(12);
    //objeto dentro da garra
    glPushMatrix();
        /*glTranslated(0,-2,0);
        glutSolidSphere(0.5,100,100);*/
        desenhaGarra(crdGarra, grrGarra);
    glPopMatrix();
    // caixa da Garra...
    glPushMatrix();
        glTranslated(0,0,0);
        desenhaCuboCustomizado(5,corObjeto);
    glPopMatrix();

    

    glutSwapBuffers();
}

void Redimensiona(int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
    gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
}

void Teclado(unsigned char key, int x, int y){
    switch (key) {
        // Tecla ESC
        case 27:
            exit(0);
            break;

        case 'a'://camera vira para direita
            if(crdCamera.fltX<=2.4){
                crdCamera.fltX +=0.3;
                cout << crdCamera.fltX << endl;
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glTranslatef (0.0, 0.0, -5.0);
                gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
            }
            break;

        case 'd'://camera vira para esquerda
            if(crdCamera.fltX>=-4.8){
                crdCamera.fltX -= 0.3;
                cout << crdCamera.fltX << endl;
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glTranslatef (0.0, 0.0, -5.0);
                gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
            }
            break;

        case 'x'://garra fecha
            if (grrGarra.intDireita < 30)
                grrGarra.intDireita = (grrGarra.intDireita + 5) % 360;
            if (grrGarra.intEsquerda < 30)
                grrGarra.intEsquerda = ((grrGarra.intEsquerda + 5) % 360);
            if (grrGarra.intInferior < 30)
                grrGarra.intInferior = (grrGarra.intInferior + 5) % 360;
            if (grrGarra.intSuperior < 30)
                grrGarra.intSuperior = (grrGarra.intSuperior + 5) % 360;
            glutPostRedisplay();
            break;

        case 'z'://gara abre
            if (grrGarra.intDireita > 0)
                grrGarra.intDireita = (grrGarra.intDireita - 5) % 360;
            if (grrGarra.intEsquerda > 0)
                grrGarra.intEsquerda = (grrGarra.intEsquerda - 5) % 360;
            if (grrGarra.intInferior > 0)
                grrGarra.intInferior = (grrGarra.intInferior - 5) % 360;
            if (grrGarra.intSuperior > 0)
                grrGarra.intSuperior = (grrGarra.intSuperior - 5) % 360;
            glutPostRedisplay();
            break;

        default:
            break;
    }
}

void MovimentaGarra(int key, int x, int y){
    if(key == GLUT_KEY_UP){
        crdGarra.fltZ++;
    }
    if(key == GLUT_KEY_DOWN){
        crdGarra.fltZ--;
    }
    if(key == GLUT_KEY_RIGHT){
        crdGarra.fltX++;
    }
    if(key == GLUT_KEY_LEFT){
        crdGarra.fltX--;
    }
}

void Update(){
    glutPostRedisplay();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("O GARRA");
    setupTexturasSkybox();
    glutReshapeFunc(Redimensiona);
    Inicializa();
    glutDisplayFunc(Desenha);
    
    
    glutKeyboardFunc(Teclado);
    glutSpecialFunc(MovimentaGarra);
    glutIdleFunc(Update);
    glutMainLoop();
    return 0;
}
