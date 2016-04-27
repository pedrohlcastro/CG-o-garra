enum tipoObjetoFundo{ESFERA, CUBO};

typedef struct objetosFundo{
	struct Coordenadas crdObjetosFundo;
	int intTipo;
	float fltTamanhoObjeto;
}objetosFundo;

int setObjetosFundo(int, float);
void desenhaObjetosFundo(int);
int Colisao(Coordenadas, int,int *intQtdPedente);
void LevantaObjeto(int);
void MovimentaObjetoEixoX(int);
void MovimentaObjetoEixoZ(int);
bool DesceObjeto();
