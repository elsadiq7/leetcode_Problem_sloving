#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
            string word_1="", word_2="";
            for (string str : word1) {
                 word_1+=str;
            }
    
            for (string str : word2) {
                 word_2+=str;
            }
    
            return word_1==word_2;
    
        }
    };