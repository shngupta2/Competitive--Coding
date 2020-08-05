// Question : https://leetcode.com/problems/jump-game-iii/submissions/

class Solution {
public:
    bool solve(vector <int>& arr, int ind) {
        if(ind < 0 || ind >= arr.size() || arr[ind] < 0)
            return false;
        
        if(arr[ind] == 0)
            return true;
       
        int k = arr[ind];
        arr[ind] = -1;
        return solve(arr, ind + k) || solve(arr, ind - k);
        arr[ind] = k;
    }
    bool canReach(vector<int>& arr, int start) {
        return solve(arr, start);
    }
};
