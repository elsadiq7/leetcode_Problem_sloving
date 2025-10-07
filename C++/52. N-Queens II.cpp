class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> cols(n, false);      // track columns
        vector<bool> diag1(2 * n, false); // track \ diagonals (row - col + n)
        vector<bool> diag2(2 * n, false); // track / diagonals (row + col)

        solve(0, n, cols, diag1, diag2, count);
        return count;
    }
    void solve(int row, int n, vector<bool>& cols, vector<bool>& diag1,
               vector<bool>& diag2, int& count) {

        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {        

            if(cols[col] || diag1[row - col + n] || diag2[row + col]) continue;

            cols[col] = diag1[row - col + n] = diag2[row + col] = true;
            solve(row + 1, n, cols, diag1, diag2, count);

            cols[col] = diag1[row - col + n] = diag2[row + col] = false;


         }

            
    }
};