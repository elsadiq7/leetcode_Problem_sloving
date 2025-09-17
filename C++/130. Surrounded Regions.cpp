class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

         for(int i=0;i<rows;i++)
         {
            for(int j=0;j<cols;j++)
            {
                if( (i==0||j==0||i==rows-1||j==cols-1)&& (board[i][j] == 'O' && !visited[i][j]))
                { 
                    bfs(i,j,board,visited);
                }
            }
         }


         
         for(int i=0;i<rows;i++)
         {
            for(int j=0;j<cols;j++)
            {
                if(board[i][j]=='S')
                { 
                    board[i][j]='O';
                }
                else if (board[i][j]=='O')
                {
                     board[i][j]='X';
                }
            }
         }



    }

private:
    void bfs(int startRow, int startCol, vector<vector<char>>& board,
             vector<vector<bool>>& visited) {
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int, int>> q;
        q.push({startRow, startCol});
        visited[startRow][startCol] = true;

        // 4-directional moves: down, up, right, left
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // mark current cell as safe
            board[r][c] = 'S';

            for (auto [dr, dc] : directions) {
                int newRow = r + dr;
                int newCol = c + dc;

                if (newRow >= 0 && newRow < rows &&
                    newCol >= 0 && newCol < cols &&
                    board[newRow][newCol] == 'O' &&
                    !visited[newRow][newCol]) {
                    
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
    }
};
