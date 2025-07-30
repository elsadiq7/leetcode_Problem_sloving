class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        // Step 1: Count characters in t
        unordered_map<char, int> target;
        for (char c : t) target[c]++;

        unordered_map<char, int> window;
        int have = 0, need = target.size();

        int left = 0, minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            window[c]++;

            if (target.count(c) && window[c] == target[c]) {
                have++;
            }

            while (have == need) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;
                if (target.count(leftChar) && window[leftChar] < target[leftChar]) {
                    have--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
