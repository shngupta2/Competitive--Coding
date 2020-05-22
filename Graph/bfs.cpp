#include <iostream>
#include <vector>
#include <queue>
using namespace std;
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
while(!q.empty()) {
	int k = q.front();
	if(visited[k] == 0)
		cout<<k + 1<<" ";
	visited[k] = 1;
	q.pop();
	for(int i = 0; i < adj[k].size(); i++) {
		int m = adj[k][i];
		if(visited[m] == 0) {
			q.push(adj[k][i]);
		}
	}
}

return 0;

}
