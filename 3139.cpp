#define ll long long

class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2)
    {
        const int MOD = 1e9 + 7;
        ll sum = 0;
        ll mini = LONG_LONG_MAX;
        ll maxi = 0;

        for (int num : nums) {
            maxi = max(maxi, 1LL * num);
            mini = min(mini, 1LL * num);
            sum += num;
        }

        ll N = nums.size();
        ll ans = LONG_LONG_MAX;

        for (ll target = maxi; target <= 2 * maxi; target++) {
            ll longestGap = target - mini;
            ll changesRequired = target * N - sum;
            ll cur;

            if (2 * cost1 <= cost2) {
                cur = changesRequired * cost1;
            }
            else {
                ll last = changesRequired - longestGap;
                if (last < longestGap) {
                    cur = (longestGap - last) * cost1 + last * cost2;
                }
                else if (changesRequired % 2 == 0) {
                    cur = (changesRequired / 2) * cost2;
                }
                else {
                    cur = (changesRequired / 2) * cost2 + cost1;
                }
            }

            ans = min(ans, cur);
        }

        return ans % MOD;
    }
};