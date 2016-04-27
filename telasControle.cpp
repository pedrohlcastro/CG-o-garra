#include <GL/glew.h>
#include <GL/freeglut.h>

#ifdef WIN32
    #include <SOIL.h>
#else
    #include <SOIL/SOIL.h>
#endif

#include <bits/stdc++.h>
#include "estruturas_basicas.h"
#include "telasControle.h"

using namespace std;


int intImagens[4];

void setupImagensMenus(){
    intImagens[IMG_LOADING]= SOIL_load_OGL_texture(
        #ifdef WIN32
            "img/LOADING_PAGE.png",
        #else
            "../img/LOADING_PAGE.png",
        #endif
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (intImagens[IMG_LOADING] == 0 ) {
        printf("Erro carregando textura: '%s'\n", SOIL_last_result());
    }

    intImagens[IMG_MENU]= SOIL_load_OGL_texture(
        #ifdef WIN32
            "img/MAIN_MENU.png",
        #else
            "../img/MAIN_MENU.png",
        #endif
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (intImagens[IMG_MENU] == 0 ) {
        printf("Erro carregando textura: '%s'\n", SOIL_last_result());
    }
    intImagens[IMG_WIN]= SOIL_load_OGL_texture(
        #ifdef WIN32
            "img/GANHOU.png",
        #else
            "../img/GANHOU.png",
        #endif
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (intImagens[IMG_WIN] == 0 ) {
        printf("Erro carregando textura: '%s'\n", SOIL_last_result());
    }
    intImagens[IMG_LOSE]= SOIL_load_OGL_texture(
        #ifdef WIN32
            "img/PERDER.png",
        #else
            "../img/PERDEU.png",
        #endif
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (intImagens[IMG_LOSE] == 0 ) {
        printf("Erro carregando textura: '%s'\n", SOIL_last_result());
    }
}

void desenhaTelasControle(int intEscolha,float spriteBegin,float spriteEnd){
	glColor4f(1,1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, intImagens[intEscolha]);
	glPushMatrix();
		glTranslatef(-250,-250,0);
		glBegin(GL_QUADS);
			glTexCoord2f(spriteBegin, 0); 					glVertex2f(0,0);
			glTexCoord2f(spriteEnd, 0);						glVertex2f(500,0);
  			glTexCoord2f(spriteEnd, 1); 					glVertex2f(500,500);
  			glTexCoord2f(spriteBegin, 1);					glVertex2f(0,500);			
		glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
