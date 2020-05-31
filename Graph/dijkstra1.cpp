//Question https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

int mind(vector <int>& dist, vector <int>& visited) {
    int min = INT_MAX;
    int index;
    for(int i = 0; i < dist.size(); i++) {
        if(visited[i] == 0 && min > dist[i]) {
            min = dist[i];
            index = i;
        }
    }
    
    return index;
}

vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    int n = g.size();
    vector <int> visited(V, 0);
    vector <int> dist(V, INT_MAX);
    dist[src] = 0;
    for(int i = 0; i < V - 1; i++) {
        int u = mind(dist, visited);
        visited[u] = 1;
        
        for(int v = 0; v < g[u].size(); v++) {
            if(visited[v] == 0 && g[u][v] && dist[v] > dist[u] + g[u][v] && dist[u] != INT_MAX)
                dist[v] = dist[u] + g[u][v];
        }
    }
    return dist;
    // Your code here
}
