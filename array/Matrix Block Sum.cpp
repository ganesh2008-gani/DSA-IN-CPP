
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i + 1][j + 1] = mat[i][j]
                    + prefix[i + 1][j]
                    + prefix[i][j + 1]
                    - prefix[i][j];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int row1 = max(0, i - k);
                int col1 = max(0, j - k);
                int row2 = min(m - 1, i + k);
                int col2 = min(n - 1, j + k);

                ans[i][j] = prefix[row2 + 1][col2 + 1]
                    - prefix[row2 + 1][col1]
                    - prefix[row1][col2 + 1]
                    + prefix[row1][col1];
            }
        }

        return ans;
    }
};
