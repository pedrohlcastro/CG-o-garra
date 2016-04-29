#include <GL/glew.h>
#include <GL/freeglut.h>
#ifdef WIN32
    #include <SOIL.h>
#else
    #include <SOIL/SOIL.h>
#endif
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include "skybox.h"
#include "estruturas_basicas.h"
#include "garra.h"
#include "desenho.h"
#include "objetos_fundo.h"
#include "telasControle.h"
#include "funcoes2D.h"

using namespace std;

Coordenadas crdCamera = {0, 1, 3};
Coordenadas crdTamanhoMinimoCubo = {-2, -2, -2};
Coordenadas crdTamanhoMaximoCubo = {2, 2, 2};
Garra grrGarra = {0, 0, 0 ,0, {-2.0, 2.0, -2.0}};
Cor corMaquina= {1, 0.5 , 0 , 1};

int intTempo = 0;
bool blnMovimentacaoHabilidata = true;
int intQtdObjetosFundo;
int intIndexObjeto = -1;

enum Telas{LOADING,MENU,JOGO,GAMEOVER,GANHOU};
Telas TelaAtual=LOADING;
float fltSpriteBegin=0,fltSpriteEnd=1;
float fltHeight,fltWidth;
sf::Music musicPrincipal;
int intTimer=0;
int intQtdPedente=5;
bool blnVisaoPanoramica=false;
bool blnColidiuPrimeiraVez=false;

static long font = (long)GLUT_BITMAP_8_BY_13;

void Inicializa(){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);

    //carrega skybox
    setupTexturasSkybox();
    //carrega objetos fundo...
    intQtdObjetosFundo = setObjetosFundo(1,5);   
    setupLogoDesenhoMaquina();
    #ifdef WIN32
        musicPrincipal.openFromFile("sounds/som_espacial.ogg");
    #else
        musicPrincipal.openFromFile("../sounds/som_espacial.ogg");    
    #endif
    musicPrincipal.setLoop(true);
    musicPrincipal.setVolume(30);
    musicPrincipal.play();
}

void Desenha(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable (GL_BLEND);
    glEnable(GL_LIGHTING);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    
    switch(TelaAtual){
        case JOGO:{

            glEnable(GL_DEPTH_TEST);

            //fonte de luz Posicional           
            float luzPosition[]={0, 0, 0, 1};
            float solPosition[]={-1, 0, 1, 0};

            //luz no centro do topo da maquina...
            float fltLuzAmb[] = { 0, 0, 0, 0 };
            float fltLuzDif[] = { 1.0, 1.0, 1.0, 1.0 };
            float fltLuzSpec[] = { 1, 1, 1, 1.0 };
            float fltLuzGlobal[]={ 0.5, 0.5, 0.5, 0 };

            //propriedadas da "lampada" e de luz Global
            glLightfv(GL_LIGHT0, GL_AMBIENT, fltLuzAmb);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, fltLuzDif);
            glLightfv(GL_LIGHT0, GL_SPECULAR, fltLuzSpec);
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, fltLuzGlobal);

            //propriedadas da "lampada" e de luz Global
            glLightfv(GL_LIGHT1, GL_AMBIENT, fltLuzAmb);
            glLightfv(GL_LIGHT1, GL_DIFFUSE, fltLuzDif);
            glLightfv(GL_LIGHT1, GL_SPECULAR, fltLuzSpec);


            // Desanhando a lampada 0...
            glDisable(GL_LIGHTING);
            glPushMatrix();
                glLightfv(GL_LIGHT0, GL_POSITION, luzPosition);
                glTranslatef(0, 3, 0);
                glColor3f(0.5, 0.5, 0.5);
            glPopMatrix();

            glPushMatrix();
                glLightfv(GL_LIGHT1, GL_POSITION, solPosition);
                glTranslatef(-10, -10, 0);
                glColor3f(1, 1, 1);
            glPopMatrix();


            //desenhando cena
            glEnable(GL_LIGHTING);
            glEnable(GL_LIGHT0);
            glEnable(GL_LIGHT1);
            desenhaSkybox(12);

            glEnable(GL_LIGHTING);
            //Cores de luz usadas
            float fltLuzBranca[]={1,1,1,1};
            float fltLuzLaranja[]={1, 0.5 , 0 , 1};
            float fltLuzPreta[]={0,0,0,1};
            float fltLuzBrancaReflexo[]={1, 1, 1, 0.2}; //vidro
            float fltMaterialLiso[]={60}; //quao liso o material é

            //luz especular dos materiais...
            glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,fltLuzSpec);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,fltMaterialLiso );



            fltLuzBrancaReflexo[0]=80;
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,fltMaterialLiso );
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, fltLuzLaranja);
            desenhaMaquina(5,corMaquina);

            //objeto dentro da garra
            glPushMatrix();
                fltMaterialLiso[0]=60;
                glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,fltMaterialLiso );
                desenhaObjetosFundo(intQtdObjetosFundo);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, fltLuzBranca);
                desenhaGarra(grrGarra);
            glPopMatrix();

            // caixa da Garra...
            glPushMatrix();
                glTranslated(0,0,0);
                glColor3f(1,1,1);
                fltMaterialLiso[0]=128;
                glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,fltMaterialLiso );
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, fltLuzBrancaReflexo);
                glutSolidCube(5);
            glPopMatrix();           
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, fltLuzBranca);

            DesenhaParte2D(intTimer,crdCamera,intQtdPedente);
            
            break;
        }


        case LOADING:{
            //carrega modelo de visao 2d
            glDisable(GL_DEPTH_TEST);
            glDisable(GL_LIGHTING);
            glMatrixMode (GL_PROJECTION);
            glLoadIdentity ();
            gluOrtho2D (-250, 250, -250, 250);
            desenhaTelasControle(IMG_LOADING,fltSpriteBegin,fltSpriteEnd);
            break;
        }


        case MENU:{
            //carrega modelo de visao 2d
            glDisable(GL_DEPTH_TEST);
            glDisable(GL_LIGHTING);
            glMatrixMode (GL_PROJECTION);
            glLoadIdentity ();
            gluOrtho2D (-250, 250, -250, 250);
            desenhaTelasControle(IMG_MENU,fltSpriteBegin,fltSpriteEnd);
            break;
        }

        case GAMEOVER:{
            //carrega modelo de visao 2d
            glDisable(GL_DEPTH_TEST);
            glDisable(GL_LIGHTING);
            glMatrixMode (GL_PROJECTION);
            glLoadIdentity ();
            gluOrtho2D (-250, 250, -250, 250);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            desenhaTelasControle(IMG_LOSE,fltSpriteBegin,fltSpriteEnd);
            break;
        }

        case GANHOU:{
            //carrega modelo de visao 2d
            glDisable(GL_DEPTH_TEST);
            glDisable(GL_LIGHTING);
            glMatrixMode (GL_PROJECTION);
            glLoadIdentity ();
            gluOrtho2D (-250, 250, -250, 250);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            desenhaTelasControle(IMG_WIN,fltSpriteBegin,fltSpriteEnd);
            break;
        }
    }

    glutSwapBuffers();
}

void Redimensiona(int w, int h){
    if(TelaAtual==JOGO){
        glViewport (0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef (0.0, 0.0, -5.0);
        gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
        fltWidth=w;
        fltHeight=h;
    }
    else{
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if(w>h){
            glViewport((w-h)/2,0,h,h);
        }
        if(h>w){
            glViewport(0,(h-w)/2,w,w);
        }
        glMatrixMode(GL_PROJECTION);
        glOrtho(-250, 250, -250, 250,-1,1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        fltWidth=w;
        fltHeight=h;
    }
    
}

void timerTempo(int value){
    intTimer++;
    if(intTimer==48){
        TelaAtual=GAMEOVER;
    }
    else{
        glutTimerFunc(1000,timerTempo,0);
    }
}

void Teclado(unsigned char key, int x, int y){
    if(TelaAtual==JOGO){
        switch (key) {
            case 'a'://camera vira para direita
                if(crdCamera.fltX<=1.5 && !blnVisaoPanoramica){
                    crdCamera.fltX +=0.3;
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glTranslatef (0.0, 0.0, -5.0);
                    gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
                }
                break;

            case 'd'://camera vira para esquerda
                if(crdCamera.fltX>=-1.5 && !blnVisaoPanoramica){
                    crdCamera.fltX -= 0.3;
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glTranslatef (0.0, 0.0, -5.0);
                    gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
                }
                break;

            case 'w'://camera sobe
                if(crdCamera.fltY<=1 && !blnVisaoPanoramica){
                    crdCamera.fltY +=0.3;
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glTranslatef (0.0, 0.0, -5.0);
                    gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
                }
                break;

            case 's'://camera desce
                if(crdCamera.fltY>=-0.2 && !blnVisaoPanoramica){
                    crdCamera.fltY -= 0.3;
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glTranslatef (0.0, 0.0, -5.0);
                    gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
                }
                break;

            case 'p'://visao panoramica
                crdCamera.fltX=0;
                crdCamera.fltY=1;
                if(crdCamera.fltZ==8){
                    crdCamera.fltZ=3;
                    blnVisaoPanoramica=false;
                }
                else{
                    crdCamera.fltZ=8;
                    blnVisaoPanoramica=true;
                }
                gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
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
        }
    }
    if(TelaAtual==MENU){
        if(key==ENTER){
            if(fltSpriteBegin==0){
                //carrega modelo de visao 3d para jogo...
                glViewport (0, 0, fltWidth, fltHeight);
                glMatrixMode (GL_PROJECTION);
                glLoadIdentity();
                gluPerspective(60.0, fltWidth/fltHeight, 1.0, 20.0);
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glTranslatef (0.0, 0.0, -5.0);
                gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glTranslatef (0.0, 0.0, -5.0);
                gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
                intTimer=0;
                intQtdPedente=5;
                glutTimerFunc(0,timerTempo,0);
                fltSpriteBegin=0;
                fltSpriteEnd=1;
                TelaAtual=JOGO;
            }
            else{
                //code
                //TelaAtual=CREDITOS;
            }
        }
    }
    if(TelaAtual==GAMEOVER || TelaAtual==GANHOU){
        if(key=='r' || key=='R'){
            //carrega modelo de visao 3d para jogo...
            glViewport (0, 0, fltWidth, fltHeight);
            glMatrixMode (GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(60.0, fltWidth/fltHeight, 1.0, 20.0);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef (0.0, 0.0, -5.0);
            gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef (0.0, 0.0, -5.0);
            gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);
            intTimer=0;
            intQtdPedente=5;
            glutTimerFunc(0,timerTempo,0);
            fltSpriteBegin=0;
            fltSpriteEnd=1;
            TelaAtual=JOGO;
        }
    }
    if(key==ESC){
        exit(0);
    }
}

void MovimentaGarra(int key, int x, int y){
    if(TelaAtual==JOGO){
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
    if(TelaAtual==MENU){
        if(key == GLUT_KEY_UP){
            fltSpriteBegin=0;
            fltSpriteEnd=0.5;
        }
        if(key == GLUT_KEY_DOWN){
            fltSpriteBegin=0.5;
            fltSpriteEnd=1;
        }
    }
}

void Update(){
    glutPostRedisplay();
    if(intQtdPedente==0 && blnMovimentacaoHabilidata){
        TelaAtual=GANHOU;
    }
}

void Tempo(int value){
    if(blnMovimentacaoHabilidata == false){
        grrGarra = MovimentaGarra(grrGarra, intIndexObjeto);
        blnMovimentacaoHabilidata = HabilitarMovimento();
    }
    else{
        intTempo = 0;
        blnColidiuPrimeiraVez=false;
    }
    glutTimerFunc(300, Tempo, 0);
}
void CameraSutil(int x, int y){
    if(TelaAtual==JOGO && !blnVisaoPanoramica){
        if(x>(fltWidth-100)){
            crdCamera.fltX =0.9;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef (0.0, 0.0, -5.0);
            gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);        
        }
        else{
            if(x<100){
                crdCamera.fltX =-0.9;
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glTranslatef (0.0, 0.0, -5.0);
                gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);              
            }
            else{
                crdCamera.fltX =0;
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glTranslatef (0.0, 0.0, -5.0);
                gluLookAt(crdCamera.fltX, crdCamera.fltY, crdCamera.fltZ, 0, 0, 0, 0, 1, 0);        
            }
        }
    }
}

void VerificaColisao(int value){
    int intRetorno;
    intRetorno = Colisao(GetCoordenadaEsfera(), intQtdObjetosFundo,&intQtdPedente);
    if(intRetorno != 15){
        intIndexObjeto = intRetorno;
        if(!blnColidiuPrimeiraVez){
            intQtdPedente--;
            blnColidiuPrimeiraVez=true;
        }
    }
    if(intRetorno==15)
        intIndexObjeto=-1;
    glutTimerFunc(0, VerificaColisao, 0);
}

void LoadingTimer(int value){
    TelaAtual=MENU;
    fltSpriteBegin=0;
    fltSpriteEnd=0.5;
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("O GARRA MISSAO ESPACIAL");
    glutReshapeFunc(Redimensiona);
    setupImagensMenus();
    glutDisplayFunc(Desenha);
    glutKeyboardFunc(Teclado);
    glutSpecialFunc(MovimentaGarra);
    glutIdleFunc(Update);
    glutPassiveMotionFunc(CameraSutil);
    glutTimerFunc(0, Tempo, 0);
    Inicializa();
    glutTimerFunc(3500,LoadingTimer,0);
    glutTimerFunc(0, VerificaColisao, 0);
    glutMainLoop();
    return 0;
}
