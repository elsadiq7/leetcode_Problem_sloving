class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> current;
        char previous = chars[0];
        int count = 1;

        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == previous) {

                count++;
            } else {
                current.insert(current.end(), previous);
                if (count > 1) {
                    string s = to_string(count);
                    current.insert(current.end(), s.begin(), s.end());
                }

                previous = chars[i];
                count = 1;
            }
        }
        current.insert(current.end(), previous);
        if (count > 1) {
            string s = to_string(count);
            current.insert(current.end(), s.begin(), s.end());
        }

      
        for (int i = 0; i < current.size(); i++) {
            chars[i] = current[i];
        }
        return current.size();
    }
};