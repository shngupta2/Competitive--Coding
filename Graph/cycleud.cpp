#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool func(int u, vector <int>& visited, int parent,  vector <int> adj[]) {
	visited[u] = 1;
	for(int i = 0; i < adj[u].size(); i++) {
		int k = adj[u][i];
		if(visited[k] == 0) {
			func(k, visited, u, adj);
		} else if(k != parent) {
			return true;
		//	cout<<"cycle detected";
		}
	}
	return false;
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

vector <int> visited(v, 0);
if(func(0, visited, -1, adj) == true) {
	cout<<"cycle detected";
} else {
	cout<<"no cycle detected";
}

return 0;

}
