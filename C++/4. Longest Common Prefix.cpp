class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int size=min(strs[0].length(),strs[strs.size()-1].length());
        string str="";
        for (int i=0;i<size;i++)
        {
           if (strs[0][i]==strs[strs.size()-1][i])
           {
            str+=strs[0][i];
            
           }
           else
             break;
        }
        return str;
    }
};