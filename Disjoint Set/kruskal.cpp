#include <bits/stdc++.h>
using namespace std;
#define p1 pair<int, pair<int, int> >
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
	int n; // no. of nodes;
	cin>>n;    // no. of nodes;
	vector <int> parent(n, -1);
	vector <int> rank(n, 0);
	for(int i = 0; i < n; i++)
		parent[i] = i;
	
	priority_queue<p1, vector<p1>, greater<p1> > pq;
	int e;
	cin>>e;
	for(int i = 0; i < e; i++) {
		int s, d, w;
		cin>>s>>d>>w;
		pq.push(make_pair(w, make_pair(s, d)));
	}
	int res = 0;
	int count = n - 1;
	while(count != 0) {
	p1 p;
	p = pq.top();
	pq.pop();
	int w = p.first;
	int s = p.second.first;
	int d = p.second.second;
		if(find(parent, s) != find(parent, d)) {
			unions(s, d, parent, rank);
			cout<<s<<" "<<d<<" "<<w<<endl;
			res += w;
			count -= 1;
			cout<<"res "<<res<<" "<<"count "<<count<<endl;
		}
	
	}
	cout<<"res "<<res;
	return 0;
}
