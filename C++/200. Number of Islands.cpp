class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int counter = 0;

        vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1' && !visited[row][col]) {
                    bfs(row, col, grid, visited);
                    counter++;
                }
            }
        }

        return counter;
    }

private:
    void bfs(int startRow, int startCol, vector<vector<char>>& grid,
             vector<std::vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        visited[startRow][startCol] = true;
        queue<pair<int, int>> q;

        q.push({startRow, startCol});

        vector<std::pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while (!q.empty()) {
            auto [currentRow, currentCol] = q.front();
            q.pop();

            for (auto [dr, dc] : dir) {
                int newRow = currentRow + dr;
                int newCol = currentCol + dc;
                if (newRow >= 0 && newRow < m && newCol >=0
                        && newCol < n && grid[newRow][newCol] == '1' &&
                        !visited[newRow][newCol])

                {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
    }
};
