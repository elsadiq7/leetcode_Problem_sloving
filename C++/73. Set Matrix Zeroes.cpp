class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> indexs;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == 0) {
                    indexs.push_back({row, col});
                }
            }
        }

        for (int i = 0; i < indexs.size(); i++) {
            set_zero_row_col(matrix, indexs[i][0], indexs[i][1], m, n);
        }
    }
    void set_zero_row_col(vector<vector<int>>& matrix, int row, int col, int m,
                          int n) {
        for (int val = 0; val < n; val++) {
            matrix[row][val] = 0;
        }

        for (int val = 0; val < m; val++) {
            matrix[val][col] = 0;
        }
    }
};