#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

// Vertices -> par de valores (peso,vertice)
typedef pair<int, int> Vertices;

// Classe que representa o Grafo
class Grafo
{
    int V;

// Lista de adjacencias
    list< pair<int, int> > *adj;

public:
    // Metodo construtor
    Grafo(int V);

    // Funcao que adiciona aresta ao grafo..
    void AdicionarAresta(int u, int v, int w);

    void prims();
};

// Quando o grafo é criado criamos também a lista de adjacencia..
Grafo::Grafo(int V)
{
    // This-> apenas para evitar problemas com o mesmo nome de variavel ( ponteiro local )
    this->V = V;
    adj = new list<Vertices> [V];
}

void Grafo::AdicionarAresta(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

