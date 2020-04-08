#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>
#include "..\inscricoes.h"

Pais *PaisCarregaTodos() {
	//setlocale(LC_CTYPE,"UTF-16");
	Pais* listaPaises = NULL;
	Pais* actual = NULL;
	Pais* ultimo = NULL;
	
	FILE* fp = fopen(".\\db\\paises.txt", "r");
	if(!fp) return NULL;
	
	while(!feof(fp)) {
		actual = calloc(1, sizeof(Pais));
		fscanf(fp,"%d:%[^\n]", &(actual->codigo), &(actual->descricao));

		if(listaPaises == NULL) {
			listaPaises = actual;
			ultimo = listaPaises;
		}
		else {
			ultimo->next = actual;
			ultimo = actual;
		}
	}
	
	return listaPaises;
}

Pais *PaisGetByCodigo(int codigo, Pais* listaPaises) {
	if(listaPaises == NULL) return NULL;
	
	if(listaPaises->codigo == codigo) return listaPaises;
	
	return PaisGetByCodigo(codigo, listaPaises->next);
}