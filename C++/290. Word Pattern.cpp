#include <iostream>
#include <sstream>
#include <string>
#include <vector>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> hash_map_k_v;
        unordered_map<string, char> hash_map_v_k;
        istringstream iss(s);
        vector<string> words;
        string word;
        char key;
        string value;
        while (iss >> word) {
            words.push_back(word);
        }

        if (pattern.length() != words.size())
            return false;

        for (int i = 0; i < pattern.length(); i++) {
            key = pattern[i];
            value = words[i];
            if (!hash_map_k_v.count(key) && !hash_map_v_k.count(value)) {
                hash_map_k_v[key] = value;
                hash_map_v_k[value] = key;
            } else if (hash_map_k_v[key] != value || hash_map_v_k[value] != key)
                return false;
        }
        return true;
    }
};