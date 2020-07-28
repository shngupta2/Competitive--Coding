//Question https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
public:
    int n;
    vector <int> t;
    vector <int>& nums;
    
    NumArray(vector<int>& nums):nums(nums) {
        n = nums.size();
        t.resize(n + 1);
        for(int i = 0; i <= n; i++)
            t[i] = 0;
   
        for(int i = 0; i < n; i++) {
            updatetree(i, nums[i]);
        }
      
    }
    void updatetree(int i, int val) {
        i++;
        while(i < n + 1) {
            t[i] += val;
            i += (i & (-i));
        }
    }
    void update(int i, int val) {
        updatetree(i, val - nums[i]);
        nums[i] = val;
       
    }
    int getsum(int i) {
        int sum = 0;
        i++;
        while(i > 0) {
            sum += t[i];
            i -= (i & (-i));
        }
        return sum;
    }
    int sumRange(int i, int j) {
        return getsum(j) - getsum(i - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
