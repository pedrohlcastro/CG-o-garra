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

Coordenadas crdCamera = {0, 1, 3};
Coordenadas crdTamanhoMinimoCubo = {-2, -2, -2};
Coordenadas crdTamanhoMaximoCubo = {2, 2, 2};
Garra grrGarra = {0, 0, 0 ,0, {-2.0, 2.0, -2.0}};
Cor corMaquinaVidro = {1, 1, 1, 0.3};
Cor corMaquina= {1, 0.5 , 0 , 1};

int intTempo = 0;
bool blnMovimentacaoHabilidata = true;

void Inicializa(){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
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
        desenhaGarra(grrGarra);
    glPopMatrix();

    desenhaMaquina(5,corMaquina);


    // caixa da Garra...
    glPushMatrix();
        glTranslated(0,0,0);
        desenhaCuboCustomizado(5,corMaquinaVidro);
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
        case ' ':
            IniciarMovimentacaoAutomatico();
            blnMovimentacaoHabilidata = false;
            break;

        default:
            break;
    }
}

void MovimentaGarra(int key, int x, int y){
    if(key == GLUT_KEY_DOWN){
        if(grrGarra.crdGarra.fltZ < crdTamanhoMaximoCubo.fltZ && blnMovimentacaoHabilidata)
            grrGarra.crdGarra.fltZ++;
    }
    if(key == GLUT_KEY_UP){
        if(grrGarra.crdGarra.fltZ > crdTamanhoMinimoCubo.fltZ && blnMovimentacaoHabilidata)
            grrGarra.crdGarra.fltZ--;
    }
    if(key == GLUT_KEY_RIGHT){
        if(grrGarra.crdGarra.fltX < crdTamanhoMaximoCubo.fltX && blnMovimentacaoHabilidata)
            grrGarra.crdGarra.fltX++;
    }
    if(key == GLUT_KEY_LEFT){
        if(grrGarra.crdGarra.fltX > crdTamanhoMinimoCubo.fltX && blnMovimentacaoHabilidata)
            grrGarra.crdGarra.fltX--;
    }
}

void Update(){
    glutPostRedisplay();
}

void Tempo(int value){
    if(blnMovimentacaoHabilidata == false){
        grrGarra = MovimentaGarra(grrGarra);
        blnMovimentacaoHabilidata = HabilitarMovimento();
    }
    else
        intTempo = 0;

    glutTimerFunc(1000, Tempo, 0);
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
    glutTimerFunc(0, Tempo, 0);
    glutMainLoop();
    return 0;
}
