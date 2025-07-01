#include<algorithm>

class Solution {
public:
    bool isAnagram(string s, string t) {
        string s1,s2;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s==t;
    }
};