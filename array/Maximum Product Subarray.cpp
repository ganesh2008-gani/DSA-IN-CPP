#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int product = 1;

        // Left to right
        for (int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            ans = max(ans, product);

            if (product == 0)
                product = 1;
        }

        product = 1;

        // Right to left
        for (int i = nums.size() - 1; i >= 0; i--) {
            product *= nums[i];
            ans = max(ans, product);

            if (product == 0)
                product = 1;
        }

        return ans;
    }
};