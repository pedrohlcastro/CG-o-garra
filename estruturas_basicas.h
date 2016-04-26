typedef struct Coordenadas{
	float fltX, fltY, fltZ;
}Coordenadas;


typedef struct Garra{
	int intEsquerda, intSuperior, intInferior, intDireita;
	Coordenadas crdGarra;
}Garra;

typedef struct Cor{
	float fltR,fltG,fltB,fltAlfa;
}Cor;

typedef struct Luz{
	Coordenadas crdLuz;
	float fltCoodenadaHomogenea;
}Luz;

#define ENTER 13
#define ESC 27
