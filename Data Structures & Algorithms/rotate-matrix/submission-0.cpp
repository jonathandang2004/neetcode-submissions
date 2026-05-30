class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            swap(matrix[i], matrix[n - i - 1]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
// Its like flipping horizontally, then flipping across y = x to get a 90 degree rotation
// But its much harder to do horizontally here so we do vertically?
// Ohhh, flip vertically, then flip across y = -x, since y = -x is easier to judge
