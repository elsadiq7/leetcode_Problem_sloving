class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazine_hash;
        unordered_map<char, int> ransomNote_hash;
        for (char i : magazine) {
            magazine_hash[i]++;
        }
        for (char i : ransomNote) {
            ransomNote_hash[i]++;
        }

        for (auto it : ransomNote_hash) {
            if (magazine_hash[it.first] < it.second) {
                return false;
            }
        }

        return true;
    }
};