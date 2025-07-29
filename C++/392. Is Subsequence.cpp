class Solution {
public:
    bool isSubsequence(string s, string t) {
        int counter=0;
        int pointer=0;
        for (int i=0;i<s.length();i++)
        {
            for (int j=pointer;j<t.length();j++)
            {
                if (s[i]==t[j])
                {
                    counter++;
                    pointer=j+1;
                    break;
                }
            }
        }
        return counter==s.length();


        
    }
};