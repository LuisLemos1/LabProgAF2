#include "..\inscricoes.h"
#include "..\models\paises.h"
#include "..\models\cursos.h"
#include "..\models\unidadesCurriculares.h"

#include "..\views\vwPaises.h"
#include "..\views\vwCursos.h"
#include "..\views\vwUnidadesCurriculares.h"

Listagens CarregaListagens() {
	Listagens listagens;
	
	listagens.paises = PaisCarregaTodos();
	listagens.cursos = CursoCarregaTodos();
	listagens.unidadesCurriculares = UnidadeCurricularCarregaTodos();
	
	return listagens;
}

void MostraListagens(Listagens listagens) {
	PaisMostraLista(listagens.paises);
	CursoMostraLista(listagens.cursos);
	UnidadesCurricularesMostraLista(listagens.unidadesCurriculares, listagens);
}

void MostraUnidadesCurricularesCurso(Listagens listagens, int curso) {
	UnidadeCurricular* lista = UnidadeCurricularGetListaByCurso(curso, listagens.unidadesCurriculares);
	UnidadesCurricularesMostraLista(lista, listagens);
}
