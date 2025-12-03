class Solution {
public:
    int maxVowels(string s, int k) {
        int max_vowels = 0;
        int current_vowels = 0;
        for (int i = 0; i < k; i++) {
            if (is_vowels(s[i])) {
                current_vowels++;
            }
        }
        max_vowels = current_vowels;
        for (int i = k; i < s.length(); i++) {
            if (is_vowels(s[i])) {
                current_vowels++;
            }
            if (is_vowels(s[i - k])) {
                current_vowels--;
            }
            max_vowels = max(max_vowels, current_vowels);
        }
        return max_vowels;
    }
    int is_vowels(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};