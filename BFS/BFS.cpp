/*
10
7
0 4
1 4
0 2
2 4
5 6
5 7
8 9

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n; // number of verticis 
	cin >> n;
	int m; // number of edges
	cin >> m;

	vector<vector<int>> graph(n);    // graph as list,vector in vectors
	/*for (int i = 0; i < n; i++) {
		graph[i].resize(n);
	}*/
	for (int i = 0; i < n; i++) 
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// BFS with Queue
	queue<int> Q;
	int c = 0; 
	vector<int> mark(n, 0); 

	for (int i = 0; i < n; i++) {
		if (mark[i] != 0) {
			continue;
		}
		c++;
		Q.push(i);
		while (!Q.empty())
		{
			int a = Q.front();
			Q.pop();
			mark[a] = c;
			for (int j = 0; j < graph[i].size(); j++)
			{
				int d = graph[a][j];
				if (mark[d] == 0) {
					Q.push(d);
				}

			}

		}
	}

	for (int i = 0; i < mark.size(); i++) {
		cout << i << " " << mark[i] << endl; 
	}


	return 0;
}