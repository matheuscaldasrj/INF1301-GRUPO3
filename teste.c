#include <stdio.h>
#include <string.h>

struct Salas
{
	char cod[5];
	int qdtComputadores;
	int maxAlunos;
	int disponibilidade [16][5];
};

void setaCodigo(struct Salas *sala, char *codSala)
{
	strcpy(sala->cod, codSala);
}

void setaMaxAlunos(struct Salas *sala, int numeroAlunos)
{
	sala->maxAlunos = numeroAlunos;
}

void reservaSala(struct Salas *sala, int dia, int horaInicio, int horaFim)
{
	int hora = horaInicio;
	for(hora; hora < horaFim; hora++)
	{
		sala->disponibilidade [hora][dia] = 0;
	}
}
int main(void)
{
	struct Salas sala1;
	int horaini, horafim, dia;
	char *codSala = "L222";
	
	dia = 0;
	horaini = 7;
	horafim = 9;

	strcpy( sala1.cod, "L201");
	
	printf("O codigo da sala 1 e: %s\n", sala1.cod);
	printf("Mudando codigo de sala para %s\n", codSala);

	setaCodigo(&sala1, codSala);

	printf("O novo codigo e: %s \n", sala1.cod);

	reservaSala(&sala1, dia, horaini, horafim);

	printf("Verificando se a sala L222 esta ocupada ou vazia na segunda feira de 7 as 9. Se 0 esta ocupada. Se 1 esta vazia.\n");
	printf("7 horas = %d\n8 horas = %d\n", sala1.disponibilidade[7][0], sala1.disponibilidade[8][0]);

	return 0;




}
