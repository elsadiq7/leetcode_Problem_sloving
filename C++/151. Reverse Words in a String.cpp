class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += s[i];
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        word = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            if (!word.empty())
                word += " ";
            word += words[i];
        }

        return word;
    }
};
