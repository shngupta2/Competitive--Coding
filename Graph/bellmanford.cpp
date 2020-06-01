#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int e;
	cin>>e;
	vector <pair<int, pair<int, int> > > ed(e);
	vector <int> dist(n, INT_MAX);
	int src;
	cin>>src;
	
	dist[src] = 0;
	
//	for(int k = 0; k < n; k++)
//			cout<<k<<" "<<dist[k]<<endl;

	for(int i = 0; i < e; i++) {
		int w, s, d;
		cin>>w>>s>>d;
		ed[i] = make_pair(w, make_pair(s, d));
	}
	
	for(int i = 1; i <= n - 1; i++) {
		for(int j = 0; j < e; j++) {
			int w, s, d;
			w = ed[j].first;
			s = ed[j].second.first;
			d = ed[j].second.second;
			if(dist[s] + w < dist[d]) {
				dist[d] = dist[s] + w;
			}
		}
//		for(int k = 0; k < n; k++)
//			cout<<k<<" "<<dist[k]<<endl;
//		cout<<endl;
	}
	
	for(int j = 0; j < e; j++) {
			int w, s, d;
			w = ed[j].first;
			s = ed[j].second.first;
			d = ed[j].second.second;
			if(dist[s] != INT_MAX && dist[s] + w < dist[d]) {
				cout<<"graph contains negative edge cycle";
				return 0;
			}
	}
	
	for(int i = 0; i < n; i++) 
		cout<<dist[i]<<" ";
		
	return 0;
}
