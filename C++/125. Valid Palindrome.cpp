#include<string>
class Solution {
public:
    bool isPalindrome(string s) {

          int size=s.length();
          string s2 ="";
          for (int i=0;i<size;i++)
          {
            if ((s[i]>='A' && s[i]<='Z'))
            {
                s2+=s[i]+32;
            }

            else if ( (s[i]>='a' && s[i]<='z')||(s[i]>='0'&&s[i]<='9'))
            {
                 s2+=s[i];
            }
          }
          size=s2.length();
          for (int i=0;i<size/2;i++)
          {
            if(s2[i]!=s2[size-i-1])
              return false;
          }

          return true; 
    }
};