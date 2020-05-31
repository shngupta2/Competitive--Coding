vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    int n = g.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector <int> key(n, INT_MAX);
    key[src] = 0;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
     pair<int, int> n = pq.top();
     pq.pop();
    int i = n.second;
    for(int j = 0; j < V; j++) {
        if(g[i][j] > 0) {
            if(key[j] > key[i] + g[i][j]) {
                key[j] = key[i] + g[i][j];
                pq.push(make_pair(key[j], j));
                
            }
        }
    }
    }
    return key;

   // Your code here
}
