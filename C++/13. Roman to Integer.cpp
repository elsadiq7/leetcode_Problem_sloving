class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_map = {
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};
        int num=0;
        for (int i=0;i<s.length();i++)
        {
           if (roman_map[s[i]]<roman_map[s[i+1]]) 
           {
               num+=roman_map[s[i+1]]-roman_map[s[i]];
               i++;
           }
            else
           {
               num+=roman_map[s[i]];
           }
        }
        return num ;
    }
};

//link:https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=top-interview-150