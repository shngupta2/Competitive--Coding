// Question : https://leetcode.com/problems/jump-game-ii/submissions/

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int curr = 0;
        int next = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i == nums.size() - 1)
                return jumps;
            next = max(next, nums[i] + i);
            if(i == curr) {
                jumps++;
                curr = next;
            }
        }
        return -1;
    }
};
