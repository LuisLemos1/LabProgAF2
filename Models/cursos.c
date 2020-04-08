#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>
#include "..\inscricoes.h"

Curso *CursoCarregaTodos() {
	//setlocale(LC_CTYPE,"UTF-16");
	Curso* listaCursos = NULL;
	Curso* actual = NULL;
	Curso* ultimo = NULL;
	
	FILE* fp = fopen(".\\db\\cursos.txt", "r");
	if(!fp) return NULL;
	
	while(!feof(fp)) {
		actual = calloc(1, sizeof(Curso));
		fscanf(fp,"%d:%[^\n]", &(actual->codigo), &(actual->descricao));

		if(listaCursos == NULL) {
			listaCursos = actual;
			ultimo = listaCursos;
		}
		else {
			ultimo->next = actual;
			ultimo = actual;
		}
	}
	
	return listaCursos;
}

Curso *CursoGetByCodigo(int codigo, Curso* listaCursos) {
	if(listaCursos == NULL) return NULL;
	
	if(listaCursos->codigo == codigo) return listaCursos;
	
	return CursoGetByCodigo(codigo, listaCursos->next);
}