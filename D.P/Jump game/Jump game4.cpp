// Question https://leetcode.com/problems/jump-game-iv/submissions/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        map <int, vector <int> > m;
        int n = arr.size();
        for(int i = 0; i < n; i++) 
               m[arr[i]].push_back(i);
        
        int res = INT_MAX;
        queue <pair<int, int> > q;
        vector <int> vis(n, 0);
        q.push({0, 0});
        vis[0] = 1;
        while(!q.empty()) {
            pair <int, int> p = q.front();
            q.pop();
            int u = p.first;
            int d = p.second;
            if(u == n - 1)
                return d;
            if(u > 0 && vis[u - 1] == 0) {
                q.push({u - 1, d + 1});
                vis[u - 1] = 1;
            }
            if(u < n - 1 && vis[u + 1] == 0) {
                q.push({u + 1, d + 1});
                    vis[u + 1] = 1;
            }
            for(int i: m[arr[u]]) {
                if(vis[i] == 0) {
                    q.push({i, d + 1});
                    vis[i] = 1;
                }
            }
            m[arr[u]] = {};
        }
        return res;
    }
};
