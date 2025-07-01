class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string,vector<string>> hash_map;
            for (int i=0;i<strs.size();i++)
            {
                string  key=sort_str(strs[i]);
                hash_map[key].push_back(strs[i]);   
            }   
    
            vector<vector<string>> my_vec;
    
            for (const auto &pair:hash_map)
            {
                my_vec.push_back(pair.second);
            }
    
            return my_vec;
    
        }
    
        string sort_str(string str)
        {   
            sort(str.begin(),str.end());
            return str;
        }
    };