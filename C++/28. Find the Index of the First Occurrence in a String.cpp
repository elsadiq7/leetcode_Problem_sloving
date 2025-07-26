class Solution {
public:
    int strStr(string haystack, string needle) {
        int hay_len=haystack.length();
        int needle_len=needle.length();

        if (needle_len>hay_len)
           return -1;

        string temp;
        for (int i=0;i<hay_len;i++)
        {
           temp=haystack.substr(i,needle_len);
           if (temp==needle)
             return i;
        }
        return -1;
    }
};