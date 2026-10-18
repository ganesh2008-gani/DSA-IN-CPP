#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> un;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (un.find(diff) != un.end())
                return {un[diff], i};

            un[nums[i]] = i;
        }

        return {};
    }
};