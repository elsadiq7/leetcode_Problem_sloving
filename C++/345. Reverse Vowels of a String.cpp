class Solution {
public:
    string reverseVowels(string s) {
        stack<int> vowels;
        vector<bool> checker(s.length(), false);

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                vowels.push(c);
                checker[i] = true;
            }
        }
        for (int i = 0; i < s.length(); i++) {
              if(checker[i])

              {
                s[i]=vowels.top();
                vowels.pop();
              }
        }
        return s ;

    }
};