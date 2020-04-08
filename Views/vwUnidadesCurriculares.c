#include <stdio.h>
#include "..\inscricoes.h"
#include "..\models\cursos.h"

void GetAnoCurricular(char *descricao, tpAnosCurriculares anoCurricular) {
	switch(anoCurricular) {
		case tpAnosCurriculares_Primeiro:
			sprintf(descricao, "%s", "Primeiro ano");
			break;
		case tpAnosCurriculares_Segundo:
			sprintf(descricao, "%s", "Segundo ano");
			break;
		case tpAnosCurriculares_Terceiro:
			sprintf(descricao, "%s", "Terceiro ano");
			break;
		case tpAnosCurriculares_Quarto:
			sprintf(descricao, "%s", "Quarto ano");
			break;
		case tpAnosCurriculares_Quinto:
			sprintf(descricao, "%s", "Quinto ano");
			break;
		default:
			sprintf(descricao, "%s", "Ano desconhecido");
			break;		
	}
}

void GetSemestre(char *descricao, tpSemestres semestre) {
	switch(semestre) {
		case tpSemestres_Primeiro:
			sprintf(descricao, "%s", "Primeiro semestre");
			break;
		case tpSemestres_Segundo:
			sprintf(descricao, "%s", "Segundo semestre");
			break;
		default:
			sprintf(descricao, "%s", "Semestre desconhecido");
			break;		
	}
}

void UnidadesCurricularesMostraLista(UnidadeCurricular* listaUnidadesCurriculares, Listagens listagens) {
	printf("\nLISTA DE UNIDADES CURRICULARES:");
	while(listaUnidadesCurriculares) {
		char anoCurricular[50];
		char semestre[50];

		Curso* curso = CursoGetByCodigo(listaUnidadesCurriculares->codigoCurso, listagens.cursos);
		
		GetAnoCurricular(anoCurricular, listaUnidadesCurriculares->anoCurricular);
		GetSemestre(semestre, listaUnidadesCurriculares->semestre);
		
		// ********* Adicionado por Luis -> listaUnidadesCurriculares->ects
		printf("\n%s:%d:%s:%s:%s:%s", listaUnidadesCurriculares->codigo, listaUnidadesCurriculares->ects, listaUnidadesCurriculares->descricao, curso->descricao, anoCurricular, semestre);

		listaUnidadesCurriculares = listaUnidadesCurriculares->next;
	}
	printf("\n");
}