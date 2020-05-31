#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
void topsort(int v, vector<bool>& visited, stack<int>& s, vector<int> adj[]) {
	visited[v] = true;
	
	for(int i = 0; i < adj[v].size(); i++) {
		int k = adj[v][i];
		if(!visited[k])
			topsort(k, visited, s, adj);
	}	
	s.push(v);
	
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
}
cout<<endl;
stack <int> s;
vector <bool> visited(v, false);

for(int i = 0; i < v; i++) 
	if(visited[i] == false) 
		topsort(i, visited, s, adj);

while(!s.empty())  {
	cout<<s.top()<<endl;
	s.pop();
}
return 0;

}
