//Question https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

void dfs(vector <int> A[], vector <vector<bool>>& visited, int i, int j) {
    visited[i][j] = true;
    int N = visited.size();
    int M = visited[0].size();
    for(int x = i - 1; x <= i + 1; x++)
        for(int y = j - 1; y <= j + 1; y++)
            if(x >= 0 && x < N && y >= 0 && y < M)
                if(A[x][y] && !visited[x][y]) {
                    dfs(A, visited, x, y);
                    } 
}

int findIslands(vector<int> A[], int N, int M) {
    vector < vector <bool> > visited(N, vector <bool> (M, 0));
    int island = 0;
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < M; j++) 
            if(A[i][j] && !visited[i][j]) {
                island++;
                dfs(A, visited, i, j);
            }
    
    return island;
    // Your code here
}
