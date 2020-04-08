#define MAXCHR 254

typedef enum _AnosCurriculares { 
	tpAnosCurriculares_Primeiro = 1, 
	tpAnosCurriculares_Segundo = 2, 
	tpAnosCurriculares_Terceiro = 3, 
	tpAnosCurriculares_Quarto = 4, 
	tpAnosCurriculares_Quinto = 5
} tpAnosCurriculares;

typedef enum _Semestres { 
	tpSemestres_Primeiro = 1, 
	tpSemestres_Segundo = 2
} tpSemestres;

typedef struct _pais {
	int codigo;
	char descricao[MAXCHR];
	
	struct _pais* next;
} Pais;

typedef struct _curso {
	int codigo;
	char descricao[MAXCHR];
	
	struct _curso* next;
} Curso;

typedef struct _unidadeCuricular {
	char codigo[50];
	char descricao[MAXCHR];
	int codigoCurso;
	//******Adicionado por Luis -> int ects	
	int ects;
	tpAnosCurriculares anoCurricular;
	tpSemestres semestre;
	
	struct _unidadeCuricular* next;
} UnidadeCurricular;

typedef struct _listagens {
	Pais* paises;
	Curso* cursos;
	UnidadeCurricular* unidadesCurriculares;
} Listagens;

typedef struct _aluno {
	long numero;
	char nome[MAXCHR];
	int codigoPais;
} Aluno;

typedef struct _inscricoesAlunoUC {
	long numeroAluno;
	//char codigoUnidadeCurricular[]
} IncricoesAlunoUC;


