class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> spiralmatrix;

        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;
        int counter = 0;
        int dir = 0;
        while (top <= bottom && left <=right) {
            if (dir == 0) {
                for (int i = left; i < right+1; i++) {
                    spiralmatrix.push_back(matrix[top][i]);
                    counter++;
                }
                dir = 1;
                top++;
            }
           else if (dir == 1) {
                for (int i = top; i < bottom+1; i++) {
                    spiralmatrix.push_back(matrix[i][right]);
                    counter++;
                }
                dir = 2;
                right--;
            }

           else if (dir == 2) {
                for (int i = right; i >= left; i--) {
                    spiralmatrix.push_back(matrix[bottom][i]);
                    counter++;
                }
                dir = 3;
                bottom--;
            }

            else if (dir == 3) {
                for (int i = bottom; i >=top; i--) {
                    spiralmatrix.push_back(matrix[i][left]);
                    counter++;
                }
                dir = 0;
                left++;
            }

        }
        return spiralmatrix;
    }
};