class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash_map_k_v;
        unordered_map<char, char> hash_map_v_k;
        char key, value;

        for (int i = 0; i < s.length(); i++) {
            key = s[i];
            value = t[i];
            if (!hash_map_k_v.count(key) && !hash_map_v_k.count(value)) {
                hash_map_k_v[key] = value;
                hash_map_v_k[value] = key;
            } else if (hash_map_k_v[key] != value &&
                       hash_map_v_k[value] != key) {
                return false;
            }
        }

        return true;
    }
};