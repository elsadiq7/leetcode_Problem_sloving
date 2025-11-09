class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int bestL = 0;
        int bestLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if ((j - i + 1) > bestLen && isPalindrome(s, i, j)) {
                    bestL = i;
                    bestLen = j - i + 1;
                }
            }
        }

        return s.substr(bestL, bestLen);
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
