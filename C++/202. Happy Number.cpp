class Solution {
public:
    bool isHappy(int n) {
        unordered_map<string, int> hash_map;
        string num_str;
        long long sum;
        while (true) {
            num_str = to_string(n);
            if (!hash_map.count(num_str))
                hash_map[num_str] = 1;
            else
                return false;
            sum = 0;
            for (int i = 0; i < num_str.length(); i++) {
                sum += (num_str[i] - '0') *(num_str[i] - '0');
            }

            if (sum == 1)
                return true;
            else
                n = sum;
        }
        return true;
    }
};