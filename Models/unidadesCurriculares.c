#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <locale.h>
#include "..\inscricoes.h"

void append(char* s, char c) {
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

UnidadeCurricular* CopiaUnidadeCurricular(UnidadeCurricular* unidadeCurricular) {
	UnidadeCurricular* novaUnidadeCurricular = NULL;
	
	if(unidadeCurricular == NULL) return NULL;
	novaUnidadeCurricular = calloc(1, sizeof(UnidadeCurricular));
	strcpy(novaUnidadeCurricular->codigo, unidadeCurricular->codigo);
	strcpy(novaUnidadeCurricular->descricao, unidadeCurricular->descricao);
	novaUnidadeCurricular->codigoCurso, unidadeCurricular->codigoCurso;
	novaUnidadeCurricular->anoCurricular, unidadeCurricular->anoCurricular;
	novaUnidadeCurricular->semestre, unidadeCurricular->semestre;
	
	return novaUnidadeCurricular;
}

UnidadeCurricular *UnidadeCurricularCarregaTodos() {
	//setlocale(LC_CTYPE,"UTF-16");
	UnidadeCurricular* listaUnidadesCurriculares = NULL;
	UnidadeCurricular* actual = NULL;
	UnidadeCurricular* ultimo = NULL;
	char c;
	int col = 1;
	int count = 0;
	bool newLine = true;
	char valor[10];
	
	
	FILE* fp = fopen(".\\db\\unidadescurriculares.txt", "r");
	if(!fp) return NULL;
	
	while ((c = getc(fp)) != EOF) {
		if(c == '\n') {
			newLine = true;
		}
		else {
			if (newLine) {
				actual = calloc(1, sizeof(UnidadeCurricular));
				col = 1;
				count = 0;
				newLine = false;
				
				if(listaUnidadesCurriculares == NULL) {
					listaUnidadesCurriculares = actual;
					ultimo = listaUnidadesCurriculares;
				}
				else {
					ultimo->next = actual;
					ultimo = actual;
				}
			} 
			
			if(c == ':') {
				col++;
				count = 0;
			}
			else {
				switch(col) {
					case 1:
						actual->codigo[count++] = c;
						break;
					case 2:
						//*****Adicionado por Luis: case 2 para ects
						//ects
						sprintf(valor,"%d", actual->ects);
						append(valor, c);
						actual->ects = atoi(valor);
						break;	
					case 3:
						actual->descricao[count++] = c;
						break;
					case 4:
						//Curso
						sprintf(valor,"%d", actual->codigoCurso);
						append(valor, c);
						actual->codigoCurso = atoi(valor);
						break;
					case 5:
						//Ano Curricular
						sprintf(valor,"%d", actual->anoCurricular);
						append(valor, c);
						actual->anoCurricular = atoi(valor);
						break;
					case 6:
						//Semestre
						sprintf(valor,"%d", actual->semestre);
						append(valor, c);
						actual->semestre = atoi(valor);
						break;
					default:
						break;
				}
			}
		}
	}
	
	return listaUnidadesCurriculares;
}

UnidadeCurricular *UnidadeCurricularGetByCodigo(char* codigo, UnidadeCurricular* listaUnidadesCurriculares) {
	if(listaUnidadesCurriculares == NULL) return NULL;
	
	if(strcmp(listaUnidadesCurriculares->codigo, codigo) == 0) return listaUnidadesCurriculares;
	
	return UnidadeCurricularGetByCodigo(codigo, listaUnidadesCurriculares->next);
}

UnidadeCurricular *UnidadeCurricularGetListaByCurso(int codigoCurso, UnidadeCurricular* listaUnidadesCurriculares) {
	UnidadeCurricular* lista = NULL;
	UnidadeCurricular* ultima = NULL;
	UnidadeCurricular* copia = NULL;
	
	while(listaUnidadesCurriculares != NULL) {
		if (listaUnidadesCurriculares->codigoCurso == codigoCurso) {
			copia = CopiaUnidadeCurricular(listaUnidadesCurriculares);
			if(lista == NULL) {
				lista = copia;
				ultima = lista;
			}
			else {
				ultima->next = copia;
				ultima = copia;
			}
		}
		
		listaUnidadesCurriculares = listaUnidadesCurriculares->next;
	}
	
	return lista;
}