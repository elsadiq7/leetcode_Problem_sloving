#include <iostream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
       vector<string> lines;
       
       string  temp="";
       int current_size=0;
       for (int i=0;i<words.size();i++) 
       {
            if (words[i].length()+current_size<=maxWidth)
            {
                temp=temp+words[i]+" ";
                current_size+=words[i].length()+1;
            }
            else 
            {
                lines.push_back(temp.substr(0,current_size-1));
                temp="";
                temp+=words[i]+" ";
                current_size=words[i].length()+1;
            }
       }
       
       int diff=maxWidth-current_size;
       for (int i=0;i<diff;i++)
       {
        temp+=" ";
       }
       lines.push_back(temp);

       return lines;
    }

};