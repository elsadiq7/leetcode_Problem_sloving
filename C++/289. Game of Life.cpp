class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> copy = board;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int sum = 0;

                // Orthogonal directions
                if (row - 1 >= 0) sum += copy[row - 1][col];       // up
                if (row + 1 < m)  sum += copy[row + 1][col];       // down
                if (col - 1 >= 0) sum += copy[row][col - 1];       // left
                if (col + 1 < n)  sum += copy[row][col + 1];       // right

                // Diagonal directions
                if (row - 1 >= 0 && col - 1 >= 0) sum += copy[row - 1][col - 1]; // up-left
                if (row - 1 >= 0 && col + 1 < n)  sum += copy[row - 1][col + 1]; // up-right
                if (row + 1 < m && col - 1 >= 0)  sum += copy[row + 1][col - 1]; // down-left
                if (row + 1 < m && col + 1 < n)  sum += copy[row + 1][col + 1]; // down-right

                // Apply Game of Life rules
                if (copy[row][col] == 1) {
                    if (sum < 2 || sum > 3)
                        board[row][col] = 0; // Dies
                } else {
                    if (sum == 3)
                        board[row][col] = 1; // Becomes alive
                }
            }
        }
    }
};
