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

Aluno *AlunoCarregaTodos() {
	//setlocale(LC_CTYPE,"UTF-16");
	Aluno* listaAlunos = NULL;
	Aluno* actual = NULL;
	Aluno* ultimo = NULL;
	char c;
	int col = 1;
	int count = 0;
	bool newLine = true;
	char valor[10];
	
	
	FILE* fp = fopen(".\\db\\alunos.txt", "r");
	if(!fp) return NULL;
	
	while ((c = getc(fp)) != EOF) {
		if(c == '\n') {
			newLine = true;
		}
		else {
			if (newLine) {
				actual = calloc(1, sizeof(Aluno));
				col = 1;
				count = 0;
				newLine = false;
				
				if(listaAluno == NULL) {
					listaAluno = actual;
					ultimo = listaAluno;
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
						//numero de aluno
					case 1:
						sprintf(valor,"%ld", actual->numero);
						append(valor, c);
						actual->numero = atoi(valor);
						break;
						//primeiro nome
					case 2:
						actual->nome[count++] = c;
						break;
						//ultimo nome		
					case 3:
						sprintf(valor,"%d", actual->codigoPais);
						append(valor, c);
						actual->numero = atoi(valor);
						break;
					default:
						break;
				}
			}
		}
	}
	
	return listaAluno;
}

Aluno *AlunoGetByNumero(int numero, Aluno* listaAluno) {
	if(listaAluno == NULL) return NULL;
	
	if(listaAluno->numero == numero) return listaAluno;
	
	return AlunoGetByNumero(numero, listaAluno->next);
}
