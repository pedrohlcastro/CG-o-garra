#include <GL/freeglut.h>

int anguloOmbro = 270, anguloCutuvelo = 0;

void Inicializa(){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void Desenha(){
    glClear (GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef (-1.0, 0.0, 0.0);
    glRotatef ((GLfloat) anguloOmbro, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glutWireCube (1.0);
    glPopMatrix();

    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) anguloCutuvelo, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glutWireCube (1.0);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void Redimensiona(int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
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
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
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
