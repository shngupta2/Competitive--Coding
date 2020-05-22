#include <iostream>
#include <vector>
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
for(int i = 0; i < v; i++) {
	for(int j = 0; j < adj[i].size(); j++) {
		cout<<adj[i][j]<<" ";
	}
	cout<<endl;
}
return 0;
}
