enum tipoObjetoFundo{BOLA,CUBO};

typedef struct objetosFundo{
	struct Coordenadas crdObjetosFundo;
	int intTipo;
	float fltTamanhoObjeto;
}objetosFundo;

void setObjetosFundo(int intQtd,float fltAreaCaixaVidro);
void desenhaObjetosFundo(int intQtd);