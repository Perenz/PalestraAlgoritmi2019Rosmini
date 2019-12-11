#include<fstream>
#include<vector>
#include<iostream>
using namespace std;

struct nodo {
	int val;
	// coppia: (vicino, peso)
	vector<pair<int, int>> vic;
	bool visitato;
};

int N, A, B;
vector<nodo> g;
int sol[101];

void dfs(int n) {
	// il nodo non è ancora stato visitato
	if (!g[n].visitato) {
		g[n].visitato = true;
		//iteriamo su tutti i vicini del nodo
		/*
		for (int i = 0; i < g[n].vic.size(); ++i) {
			printf("\tVisito arco (%d, %d)\n", n, g[n].vic[i].first);
			// mi conviene usare questo arco per raggiungere il vicino?
			if (sol[n] + g[n].vic[i].second < sol[g[n].vic[i].first]) {
				// allora dovrò ripassare da questo vicino, per aggiornare le distanze
				g[g[n].vic[i].first].visitato = false;
				// per questa iterazione aggiorno soltanto quella per lui
				sol[g[n].vic[i].first] = sol[n] + g[n].vic[i].second;
			}
			dfs(g[n].vic[i].first);
		}
		*/
		
		for (pair<int,int> vicino : g[n].vic) {
			if (sol[n] + vicino.second < sol[vicino.first]) {
				// allora dovrò ripassare da questo vicino, per aggiornare le distanze
				g[vicino.first].visitato = false;
				// per questa iterazione aggiorno soltanto quella per lui
				sol[vicino.first] = sol[n] + vicino.second;
			}
			dfs(vicino.first);	
		}

	}
}

void printGraph()
{
	for (nodo n : g) {
		cout << "Nodo " << n.val << " ha: ";
		for (pair<int,int> vicino : n.vic) {
			cout << vicino.first << " vicino, peso " << vicino.second << endl;
		}
		cout << endl;
	}
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> N >> A >> B;
	g.resize(N+1);
	for (int i = 0; i <= N; ++i)
	{
		sol[i] = A + B + 1;
		g[i].val = i;
		g[i].visitato = false;
	}
	sol[1] = 0;
	for(int i = 0; i < A; i++) {
		int a, b;
		in >> a >>b;
		// il grafo non è orientato
		// il peso dell'arco è 0 (non è bollente)
		g[a].vic.push_back(make_pair(b, 0));
		g[b].vic.push_back(make_pair(a, 0));
	}

	for(int i = 0; i < B; i++) {
		int a, b;
		in >> a >>b;
		// il peso dell'arco è 1 (è bollente)
		g[a].vic.push_back(make_pair(b, 1));
		g[b].vic.push_back(make_pair(a, 1));
	}

	//printGraph();
	dfs(1);
	out << sol[N] << endl;

	in.close();
	out.close();
	return 0;
}