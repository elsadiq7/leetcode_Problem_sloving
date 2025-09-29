class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> dist(n * n + 1, -1); // distance array
        queue<int> q;

        q.push(1);   // start at square 1
        dist[1] = 0; // 0 moves to reach square 1

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == n * n)
                return dist[curr];

            for (int dice = 1; dice <= 6 && curr + dice <= n * n; dice++) {
                int next = curr + dice;

                auto [r, c] = getCoordinates(next, n);

                if (board[r][c] != -1) {
                    next = board[r][c];
                }

                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }

        return -1; 
    }

    pair<int, int> getCoordinates(int square, int n) {
        int quot = (square - 1) / n; // row index from bottom
        int rem = (square - 1) % n;  // col index if left->right

        int row = n - 1 - quot; // convert to top-based indexing
        int col = (quot % 2 == 0) ? rem : (n - 1 - rem);

        return {row, col};
    }
};