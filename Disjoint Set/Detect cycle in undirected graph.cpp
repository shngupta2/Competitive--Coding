// video https://www.youtube.com/watch?v=n_t0a_8H8VY

#include<bits/stdc++.h>
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
	int n;
	cin>>n;    // no. of nodes;
	vector <int> parent(n, -1);
	vector <int> rank(n, 0);
	for(int i = 0; i < n; i++)
		parent[i] = i;
	
	int e;
	cin>>e;
	for(int i = 0; i < e; i++) {
		int a, b;
		cin>>a>>b;	// insert starting and end point
		if(find(parent, a) == find(parent, b))
			cout<<"cycle detected ";
		unions(a, b, parent, rank);
		
	}

	cout<<"cycle not detected";
return 0;

}
