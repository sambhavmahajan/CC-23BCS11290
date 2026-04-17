class Solution {
    vector<int> v;
    vector<int> memo;
    int k;
    int dp(int i) {
        if(i == v.size()) return 0;
        if(memo[i] != -1) return memo[i];
        int currMx = 0;
        int ret = 0;
        int currIdx;
        int len = min((int)v.size(), i + k);
        for(currIdx = i; currIdx < len; currIdx++) {
            currMx = max(v[currIdx], currMx);
            ret = max(
                ret,
                (currIdx - i + 1) * currMx + dp(currIdx + 1)
            );
        }
        return memo[i] = ret;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        v = arr;
        this->k = k;
        memo.resize((int)v.size(), -1);
        return dp(0);
    }
}; 
