class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<vector<int>> v(nums.size());
        v[0] = nums;
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = 0; j < v[i].size() - 1; j++) {
                v[i+1].push_back((v[i][j] + v[i][j + 1])%10);
            }
        }
        return v[v.size() - 1][0];
    }
}; 
