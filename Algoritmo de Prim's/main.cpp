#include "main.h"

void Grafo::prims()
{
    // Cria a fila de prioridade que armazena o vetor de vertices..
    // http://www.cplusplus.com/reference/queue/priority_queue/
    //priority_queue <Type, vector<Type>, ComparisonType > min_heap;
    // Usamos essa sintaxe para criar um Heap minimo
    priority_queue< Vertices, vector <Vertices> , greater<Vertices> > Heap_min;

    int A = 0; // Pegamos o vertice 0 como ponto de partida
    int MinimaArvore = 0;

    // Vetor com os pesos, inicialmente colocamos tudo como infinito
    vector<int> pesos(V, INF);


    // Vetor que armazena os pais dos vertices ( caminho da MST )
    vector<int> pais(V, -1);


    // Vetor booleano para saber se o vertice já foi incluso na MST, inicia todos falsos obviamente.
    vector<bool> NaMST(V, false);
    // Adiciona o A na lista de prioridade e inicia seu peso como zero..
    Heap_min.push(make_pair(0, A));
    pesos[A] = 0;

    // Trazido do pseudocodigo, itera até a heap min não chegar em zero..
    while (!Heap_min.empty())
    {

        // Extrai o vertice da fila de prioridade,
        int atual = Heap_min.top().second;
        Heap_min.pop();
        NaMST[atual] = true;  // Include vertex in MST



        list< pair<int, int> >::iterator i;
        for (i = adj[atual].begin(); i != adj[atual].end(); ++i)
        {

            int vertice = (*i).first;
            int peso = (*i).second;


            if (NaMST[vertice] == false && pesos[vertice] > peso)
            {

                pesos[vertice] = peso;
                Heap_min.push(make_pair(pesos[vertice], vertice));
                pais[vertice] = atual;
            }
        }
    }


    for (int i = 1; i < V; ++i)
        MinimaArvore += pesos[i];
        cout << "Peso Final da MST:" << endl << MinimaArvore << endl;
}

int main()
{

    int V = 9;
    Grafo g(V);

    g.AdicionarAresta(0, 1, 4);
    g.AdicionarAresta(0, 7, 8);
    g.AdicionarAresta(1, 2, 8);
    g.AdicionarAresta(1, 7, 11);
    g.AdicionarAresta(2, 3, 7);
    g.AdicionarAresta(2, 8, 2);
    g.AdicionarAresta(2, 5, 4);
    g.AdicionarAresta(3, 4, 9);
    g.AdicionarAresta(3, 5, 14);
    g.AdicionarAresta(4, 5, 10);
    g.AdicionarAresta(5, 6, 2);
    g.AdicionarAresta(6, 7, 1);
    g.AdicionarAresta(6, 8, 6);
    g.AdicionarAresta(7, 8, 7);

    g.prims();

    return 0;
}
