enum tipoObjetoFundo{ESFERA,CUBO};

typedef struct objetosFundo{
	struct Coordenadas crdObjetosFundo;
	int intTipo;
	float fltTamanhoObjeto;
}objetosFundo;

void setObjetosFundo(int intFase,float fltAreaCaixaVidro);
void desenhaObjetosFundo(int intQtd);