class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        int min_size = min(str1.length(), str2.length());
        int j = 0;

        string answer = "";
        while (j < min_size) {
            if (str1[j] == str2[j]) {
               
                if (check_divide(str1, j) && check_divide(str2, j))
                    answer = str1.substr(0, j + 1);
                 j++;

            } else {
                break;
            }
        }

        return answer;
    }
    bool check_divide(string str1, int end) {
        int start = 0;
        set<string> my_set;
        int len = end - start + 1;

        for (int i = start; i < str1.size(); i += len) {
            my_set.insert(str1.substr(i, len));
        }

        return my_set.size() == 1;
    }
};
