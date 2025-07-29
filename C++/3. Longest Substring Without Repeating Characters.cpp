class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            if (hash.count(s[right]) &&hash[s[right]]>= left) {
                left = hash[s[right]] + 1;
            }

            hash[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
