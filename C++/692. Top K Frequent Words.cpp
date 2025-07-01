#include <bits/stdc++.h>

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> hash_map;

        for (int i=0;i<words.size();i++)
        {
            if (hash_map.count(words[i]))
                hash_map[words[i]]+=1;

            else
              hash_map[words[i]]=1;
        }
        
        vector<pair<string,int>>  vec(hash_map.begin(),hash_map.end());
        sort(vec.begin(),vec.end(),[](const pair<string,int>&a,const pair<string,int>&b){
            if (a.second== b.second)
               return a.first<b.first;
            return  a.second>b.second;
        });
        
        vector<string> result(k);
        for(int i=0;i<k;i++)
        {
            result[i]=vec[i].first;
        }

        return result;

    }
};
