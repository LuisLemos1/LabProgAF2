#include <stdio.h>
#include "..\inscricoes.h"
#include "..\models\alunos.h"

void AlunosMostraLista(Alunos* listaAlunos) {
	printf("\nLISTA DE ALUNOS:");
	while(listaAlunos) {
		printf("\n%ld:%s:%d", listaAlunos->numero, listaAlunos->nome, listaAlunos->codigoPais);
		listaAlunos = listaAlunos->next;
	}
	printf("\n");
}