#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool iscycle(int v, vector<bool>& visited, vector<bool>& restack, vector <int> adj[]) {
	if(visited[v] == false) {
		visited[v] = true;
		restack[v] = true;
		
		for(int i = 0; i < adj[v].size(); i++) {
			int k = adj[v][i];
			if(!visited[k] && iscycle(k, visited, restack, adj))
				return true;
			else if(restack[k])
				return true;
		}
		
	}
	restack[v] = false;
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
//	adj[b].push_back(a);	// because of undirected graph
}
cout<<endl;

vector <bool> visited(v, false);
vector <bool> restack(v, false);

for(int i = 0; i < v; i++) {
	if(iscycle(i, visited, restack, adj)) {
	
		cout<<"cycle detected";
		return 0;
	}
}
cout<<"not detected";
return 0;

}
