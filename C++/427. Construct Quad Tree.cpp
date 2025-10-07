/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid, 0, 0, n);
    }
    Node* build(vector<vector<int>>& grid, int x, int y, int size) {
        if (isUniform(grid, x, y, size)) {
            return new Node(grid[x][y] == 1, true, nullptr, nullptr, nullptr, nullptr);
        }

        int half = size / 2;
        return new Node(
            true, // val can be anything if not leaf
            false,
            build(grid, x, y, half),
            build(grid, x, y + half, half),
            build(grid, x + half, y, half),
            build(grid, x + half, y + half, half)
        );
    }

       bool isUniform(vector<vector<int>>& grid, int x, int y, int size) {
        int val = grid[x][y];
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (grid[i][j] != val)
                    return false;
            }
        }
        return true;
    }
};