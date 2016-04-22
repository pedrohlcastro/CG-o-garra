enum tipoObjetoFundo{ESFERA,CUBO};

typedef struct objetosFundo{
	struct Coordenadas crdObjetosFundo;
	int intTipo;
	float fltTamanhoObjeto;
}objetosFundo;

int setObjetosFundo(int intFase,float fltAreaCaixaVidro);
void desenhaObjetosFundo(int intQtd);
void Colisao(Coordenadas, int);
