#include <bits/stdc++.h>
using namespace std;
int find(vector<int>& parent, int x) {
	if(parent[x] == x)
		return x;
	return find(parent, parent[x]);
	
}

void unions(int x, int y, vector <int>& parent, vector <int>& rank) {
	int xp = find(parent, x);
	int yp = find(parent, y);
	if(xp == yp)
		return;
	if(rank[xp] > rank[yp]) {
		parent[yp] = xp;
	} else if(rank[xp] < rank[yp]) {
		parent[xp] = yp;
	} else {
		parent[yp] = xp;
		rank[xp] = rank[xp] + 1;
	}
}
int main() {
	int n = 5;
//	cin>>n;
	vector <int> parent(n, -1);
	vector <int> rank(n, 0);
	for(int i = 0; i < n; i++)
		parent[i] = i;
	
	unions(0, 2, parent, rank);
	unions(4, 2, parent, rank);
	unions(3, 1, parent, rank);
	
	for(int i = 0; i < n; i++)
		cout<<i<<" "<<parent[i]<<" "<<rank[i]<<endl;
		
	return 0;
}
