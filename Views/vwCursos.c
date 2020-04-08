#include <stdio.h>
#include "..\inscricoes.h"

void CursoMostraLista(Curso* listaCursos) {
	printf("\nLISTA DE CURSOS:");
	while(listaCursos) {
		printf("\n%d:%s", listaCursos->codigo, listaCursos->descricao);
		listaCursos = listaCursos->next;
	}
	printf("\n");
}