#include <stdio.h>
#include <string.h>

struct Salas
{
	char cod[4];
	int qdtComputadores;
	int maxAlunos;
	int disponibilidade [16][4];
};

void setaNumero(struct Salas *sala, char *codSala)
{
	strcpy(sala->cod, codSala);
}

int main(void)
{
	struct Salas sala1;
	char *codSala = "L222";
	
	strcpy( sala1.cod, "L201");
	
	printf("O codigo da sala 1 e: %s\n", sala1.cod);
	printf("Mudando codigo de sala para %s\n", codSala);

	setaNumero(&sala1, codSala);

	printf("O novo codigo é %s: \n", sala1.cod);
	return 0;
}