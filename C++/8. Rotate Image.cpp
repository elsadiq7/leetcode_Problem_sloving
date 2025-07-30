class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> my_matrix(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            vector<int> row(n, 0);
            for (int j = 0; j < n; j++)
                row[j] = matrix[i][j];
            for (int j = 0; j < n; j++)
                my_matrix[j][n - i-1] = row[j];
        }

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++)
                matrix[i][j] = my_matrix[i][j];
        }
    }
};