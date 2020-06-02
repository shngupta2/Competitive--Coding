/*
* video  https://www.youtube.com/watch?v=RpgcYiky7uw&t=979s
* code help https://www.geeksforgeeks.org/strongly-connected-components/
*
* Kosaraju's Algo (used to find strongly connected components in a graph
* it is a 2 pass algorithm
* step 1- make a visited array of size no. of nodes initialize it with false;
* insert edges in both order i.e. reverse of a graph is needed in 2nd pass so make two list adj and adjr(reverse of graph)
* run dfs algo on adj if node is not visited make it visited and run dfs on its child nodes once all are visited insert it in stack.
* run second pass on revese of graph while stack not empty check if its not vsited make visited print and run dfs on its reachable nodes.
*/

#include <bits/stdc++.h>
using namespace std;

// first pass 
void dfs(int u, stack <int>& s, vector <bool>& visited, vector <int> adj[]) {
	visited[u] = true;
	for(int i = 0; i < adj[u].size(); i++) 
		if(!visited[adj[u][i]]) 
			dfs(adj[u][i], s, visited, adj);
	s.push(u);
}

// second pass
void dfs2(int u, vector <bool>& visited, vector <int> adjr[]) {
	visited[u] = true;
	cout<<u<<" ";
	for(int i = 0; i < adjr[u].size(); i++) 
		if(!visited[adjr[u][i]]) 
			dfs2(adjr[u][i], visited, adjr);
}


int main() {
	int n;
	cin>>n;
	vector <int> adj[n];
	vector <int> adjr[n];
	int e;
	cin>>e;
	for(int i = 0; i < e; i++) {
		int s, d;
		cin>>s>>d;
		adj[s].push_back(d);	// grapgh edges
		adjr[d].push_back(s);	// graph edges in reverse to create reverse of a graph
	}
	vector <bool> visited(n, false);
	stack <int> s;
	
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			dfs(i, s, visited, adj);
			cout<<endl;
		}
	}
	
	for(int i = 0; i < n; i++) 
		visited[i] = false;
	
	while(!s.empty()) {
		int u = s.top();
		s.pop();
		if(!visited[u]) {
			dfs2(u, visited, adjr);
			cout<<endl;
		}
	}
	
	return 0;
}
