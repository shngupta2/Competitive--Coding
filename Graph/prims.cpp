// Question https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    int n = graph.size();
    vector <int> visited(n, 0);
    vector <int> key(n, INT_MAX);
    key[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));
    
    for(int i = 1; i < V; i++) {
        pq.push(make_pair(INT_MAX, i));
    }
    
    int cost = 0;
    while(!pq.empty()) {
        pair<int, int> t;
        t = pq.top();
        pq.pop();
        int i = t.second;
        if(!visited[i]) {
            visited[i] = 1;
            cost += key[i];
            for(int j = 0; j < graph[i].size(); j++) {
                if(key[j] > graph[i][j] && !visited[j]) {
                    key[j] = graph[i][j];
                    pq.push(make_pair(key[j], j));
                }
            }
        }
    }
    
return cost;
    // code here
}
