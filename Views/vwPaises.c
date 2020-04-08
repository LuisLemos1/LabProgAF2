#include <stdio.h>
#include "..\inscricoes.h"

void PaisMostraLista(Pais* listaPaises) {
	printf("\nLISTA DE PAISES:");
	while(listaPaises) {
		printf("\n%d:%s", listaPaises->codigo, listaPaises->descricao);
		listaPaises = listaPaises->next;
	}
	printf("\n");
}