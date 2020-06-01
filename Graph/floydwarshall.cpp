#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector <vector <int> > adj(n, vector <int> (n, INT_MAX));
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			cin>>adj[i][j];
		
	vector <vector <int> > dist(n, vector <int> (n, INT_MAX));

	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			dist[i][j] = adj[i][j];
	
	for(int k = 0; k < n; k++) 
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < n; j++) 
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
