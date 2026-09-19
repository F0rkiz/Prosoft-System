class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long mn = nums[0];
        long long mx = nums[n - 1];

        long long S = 0;
        for (int x : nums) S += mx - x;

        long long count = 0;
        long long ans = LLONG_MAX;

        for (long long target = mx; target <= mx + 1; ++target) {
            long long curS = S + (target - mx) * n;
            long long maxDef = target - mn;

            long long curCount;
            if (cost2 >= 2 * cost1) {
                curCount = curS * cost1;
            }
            else {
                long long pairs = min(curS / 2, curS - maxDef);
                curCount = pairs * cost2 + (curS - 2 * pairs) * cost1;
            }

            ans = min(ans, curCount);
        }

        return ans % MOD;
    }
};