#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <bits/stdc++.h>
#include "skybox.h"
#include "estruturas_basicas.h"

using namespace std;

cordenadas Camera;

void Inicializa(){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
    Camera.x=0;
    Camera.y=1;
    Camera.z=3;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
    gluLookAt(Camera.x,Camera.y,Camera.z,0,0,0,0,1,0);
}

void Desenha(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1,1,1,1);
    glEnable(GL_DEPTH_TEST);

    desenhaSkybox(12);
    // caixa da Garra...
    glPushMatrix();
        glTranslated(0,0,0);
        glutWireCube(5);
    glPopMatrix();

    //objeto dentro da garra
    glPushMatrix();
        glTranslated(0,-2,0);
        glutSolidSphere(0.5,100,100);
    glPopMatrix();

    glutSwapBuffers();
}

void Redimensiona(int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
}

void Teclado(unsigned char key, int x, int y){
    switch (key) {
        // Tecla ESC
        case 27:
            exit(0);
            break;

        case 'a'://camera vira para direita
            Camera.x+=0.3;
            cout<<Camera.x<<endl;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef (0.0, 0.0, -5.0);
            gluLookAt(Camera.x,Camera.y,Camera.z,0,0,0,0,1,0);
            break;

        case 'd'://camera vira para esquerda
            Camera.x-=0.3;
            cout<<Camera.x<<endl;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef (0.0, 0.0, -5.0);
            gluLookAt(Camera.x,Camera.y,Camera.z,0,0,0,0,1,0);
            break;

        default:
            break;
    }
}

void MovimentaBraco(int key, int x, int y){
    //Movimenta ombro
    if(key == GLUT_KEY_UP){
        //anguloOmbro = (anguloOmbro + 5) % 360;
        glutPostRedisplay();
    }
    if(key == GLUT_KEY_DOWN){
        //anguloOmbro = (anguloOmbro - 5) % 360;
        glutPostRedisplay();
    }
    //Movimenta cutuvelo
    if(key == GLUT_KEY_RIGHT){
        //anguloCutuvelo = (anguloCutuvelo + 5) % 360;
        glutPostRedisplay();
    }
    if(key == GLUT_KEY_LEFT){
        //anguloCutuvelo = (anguloCutuvelo - 5) % 360;
        glutPostRedisplay();
    }
}
void update(){
    glutPostRedisplay();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Braco do Robo");
    

    glutDisplayFunc(Desenha);
    glutReshapeFunc(Redimensiona);
    Inicializa();
    glutKeyboardFunc(Teclado);
    glutSpecialFunc(MovimentaBraco);
    glutIdleFunc(update);
    glutMainLoop();
    return 0;
}
