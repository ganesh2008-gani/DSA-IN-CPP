#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum = nums[0];
        int maxending = nums[0];

        int minsum = nums[0];
        int minending = nums[0];

        int total = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            total += nums[i];

            maxending = max(nums[i], maxending + nums[i]);
            maxsum = max(maxsum, maxending);

            minending = min(nums[i], minending + nums[i]);
            minsum = min(minsum, minending);
        }

        if (maxsum < 0)
            return maxsum;

        return max(maxsum, total - minsum);
    }
};