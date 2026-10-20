
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, int> Count;
        unordered_map<int, int> totalindex;

        int prefix = 0;
        int ans = 0;

        Count[0] = 1;
        totalindex[0] = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefix ^= arr[i];

            if (Count.count(prefix)) {
                ans += Count[prefix] * i - totalindex[prefix];
            }

            Count[prefix]++;
            totalindex[prefix] += i + 1;
        }

        return ans;
    }
};
