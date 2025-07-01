class Solution {
    public:
        bool uniqueOccurrences(vector<int>& arr) {
            unordered_map<int,int> hash_map;
            for (int i=0;i<arr.size();i++)
            {
                if (hash_map.count(arr[i]))
                    hash_map[arr[i]]+=1;
                else 
                   hash_map[arr[i]]=1;
            }
            unordered_map<int,int> hash_map2;
    
            for (auto it=hash_map.begin();it!=hash_map.end();it++)
            {
                if (hash_map2.count(it->second))
                   return false;
                hash_map2[it->second]=1;
            }
            return true;
    
    
            
        }
    };