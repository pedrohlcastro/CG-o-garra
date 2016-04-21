#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>

int anguloOmbro = 270, anguloCutuvelo = 0;

void Inicializa(){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void Desenha(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1,1,1,1);
    glEnable(GL_DEPTH_TEST);

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
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
    gluLookAt(0,1,3,0,0,0,0,1,0);
}

void Teclado(unsigned char key, int x, int y){
    switch (key) {
        // Tecla ESC
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

void MovimentaBraco(int key, int x, int y){
    //Movimenta ombro
    if(key == GLUT_KEY_UP){
        anguloOmbro = (anguloOmbro + 5) % 360;
        glutPostRedisplay();
    }
    if(key == GLUT_KEY_DOWN){
        anguloOmbro = (anguloOmbro - 5) % 360;
        glutPostRedisplay();
    }
    //Movimenta cutuvelo
    if(key == GLUT_KEY_RIGHT){
        anguloCutuvelo = (anguloCutuvelo + 5) % 360;
        glutPostRedisplay();
    }
    if(key == GLUT_KEY_LEFT){
        anguloCutuvelo = (anguloCutuvelo - 5) % 360;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Braco do Robo");
    Inicializa();

    glutDisplayFunc(Desenha);
    glutReshapeFunc(Redimensiona);
    glutKeyboardFunc(Teclado);
    glutSpecialFunc(MovimentaBraco);
    glutMainLoop();
    return 0;
}
