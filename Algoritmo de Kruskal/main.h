#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Aresta {

	int origem, destino, peso;

};

struct Grafo{

	int V, A;

	struct Aresta* aresta;

};


struct Grafo* criaGrafo(int V, int A) {
	struct Grafo* grafo = new Grafo;
	grafo->V = V;
	grafo->A = A;

	grafo->aresta = new Aresta[A];

	return grafo;
}

struct subconjunto{
	int pai;
	int classificacao;
};

int buscaConjunto(struct subconjunto subconjuntos[], int i) {

	if (subconjuntos[i].pai != i)
		subconjuntos[i].pai = buscaConjunto(subconjuntos, subconjuntos[i].pai);

	return subconjuntos[i].pai;
}


void uniaoConjunto(struct subconjunto subconjuntos[], int x, int y) {

	int xroot = buscaConjunto(subconjuntos, x);
	int yroot = buscaConjunto(subconjuntos, y);

	if (subconjuntos[xroot].classificacao < subconjuntos[yroot].classificacao) {
		subconjuntos[xroot].pai = yroot;
	} else if (subconjuntos[xroot].classificacao > subconjuntos[yroot].classificacao) {
		subconjuntos[yroot].pai = xroot;
	} else {
		subconjuntos[yroot].pai = xroot;
		subconjuntos[xroot].classificacao++;
	}

}


int comparaPesos(const void* a, const void* b) {

	struct Aresta* a1 = (struct Aresta*)a;
	struct Aresta* b1 = (struct Aresta*)b;
	return a1->peso > b1->peso;

}
