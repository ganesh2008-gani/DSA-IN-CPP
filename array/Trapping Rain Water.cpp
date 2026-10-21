
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int rm = 0;
        int water = 0;
        int lm = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] > lm)
                    lm = height[l];
                else
                    water += lm - height[l];

                l++;
            } else {
                if (height[r] > rm)
                    rm = height[r];
                else
                    water += rm - height[r];

                r--;
            }
        }

        return water;
    }
};
