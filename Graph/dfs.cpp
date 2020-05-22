#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int u, vector <int> & visited, vector <int> adj[]) {
	visited[u] = 1;
	cout<<u<<" ";
	for(int i = 0; i < adj[u].size(); i++) {
		if(visited[adj[u][i]] == 0) {
			dfs(adj[u][i], visited, adj);
		}
	}
	
}
int main() {
int v;
cin>> v;    // no. of nodes;
vector <int> adj[v];  // an array of size v where each index is an vector.
int e;
cin>>e; // no. of edges
	int a, b;

for(int i = 0; i < e; i++) {
	cin>>a>>b;	// insert starting and end point
	adj[a].push_back(b);
	adj[b].push_back(a);	// because of undirected graph
}
cout<<endl;
queue <int> q;
q.push(0);

vector <int> visited(v, 0);
dfs(2, visited, adj);

return 0;

}
