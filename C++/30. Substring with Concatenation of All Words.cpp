class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int word_len = words[0].length();
        int word_count = words.size();
        int window_size = word_len * word_count;
        int s_len = s.length();

        unordered_map<string, int> wordFreq;
        for (const string& word : words) wordFreq[word]++;

        for (int offset = 0; offset < word_len; offset++) {
            int left = offset, count = 0;
            unordered_map<string, int> seen;

            for (int right = offset; right + word_len <= s_len; right += word_len) {
                string word = s.substr(right, word_len);

                if (wordFreq.count(word)) {
                    seen[word]++;
                    count++;

                    // Shrink the window if word seen too many times
                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, word_len);
                        seen[leftWord]--;
                        left += word_len;
                        count--;
                    }

                    if (count == word_count) {
                        result.push_back(left);
                    }
                } else {
                    // Reset window
                    seen.clear();
                    count = 0;
                    left = right + word_len;
                }
            }
        }

        return result;
    }
};
