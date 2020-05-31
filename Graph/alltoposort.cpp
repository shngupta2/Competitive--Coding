#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void alltoposort(int v, vector<int>& indeg, vector<int>& res, vector<bool>& visited, vector<int> adj[]) {
	bool flag = false;
	
	for(int i = 0; i < v; i++) {
		if(indeg[i] == 0 && !visited[i]) {
			for(int j = 0; j < adj[i].size(); j++) {
				int k = adj[i][j];
				indeg[k]--;
			}
			res.push_back(i);
			visited[i] = true;
			
			alltoposort(v, indeg, res, visited, adj);
			
			visited[i] = false;
			res.erase(res.end() - 1);
			for(int j = 0; j < adj[i].size(); j++) {
				int k = adj[i][j];
				indeg[k]++;
			}
			flag = true;
		}
	}
		if(!flag) {
			for(int j = 0; j < res.size(); j++)
				cout<<res[j]<<" ";
			
			cout<<endl;
		}
}

int main() {
int v;
cin>> v;    // no. of nodes;
vector <int> adj[v];  // an array of size v where each index is an vector.
int e;
cin>>e; // no. of edges
	int a, b;
vector <int> indeg(v, 0);
for(int i = 0; i < e; i++) {
	cin>>a>>b;	// insert starting and end point
	adj[a].push_back(b);
	indeg[b]++;
}

	vector <bool> visited(v, false);
	vector <int> res;
	alltoposort(v, indeg, res, visited, adj);
	
return 0;

}
