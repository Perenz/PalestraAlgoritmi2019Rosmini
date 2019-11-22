#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// ogni nodo contiene la lista dei suoi vicini
struct node {
	vector<int> vic;
	// true se il nodo è stato visitato, false altrimenti. Potrebbe servirvi?
	// bool visited;
};

// il grafo è costituito dalla lista di nodi
vector<node> graph;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	// dimensione del grafo: numero di nodi e numero di archi
	int N, M;
	in >> N >> M;
	// impostiamo la dimensione del grafo con il numero di nodi
	graph.resize(N);
	// per ogni arco che ci viene dato in input...
	for (int i = 0; i < M; i++) {
		int from, to;
		in >> from >> to;
		// aggiungiamo "to" come vicino di "from"
		graph[from].vic.push_back(to);
		// il grafo non è orientato, ripetiamo l'operazione in modo simmetrico
		graph[to].vic.push_back(from);
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < graph[i].vic.size(); j++) {
			cout << "Il nodo " << i << " e' collegato al nodo " << graph[i].vic[j] << endl;
		}
	}
	
}
