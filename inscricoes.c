#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>
#include "inscricoes.h"
#include ".\Controller\controller.h"

int main(void) {
	//setlocale(LC_CTYPE,"UTF-16");
	Listagens listagens;
	
	listagens = CarregaListagens();
	MostraListagens(listagens);
	
	MostraUnidadesCurricularesCurso(listagens, 2);

	printf("\n");
	exit(EXIT_SUCCESS);
}