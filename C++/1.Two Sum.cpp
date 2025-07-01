class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash_table;
      
        vector<int> array={0,0};
        int mid;

        for (int i=0;i<nums.size();i++)
        {
            mid=target-nums[i];
            if (hash_table.count(mid))   
            {
                array[0]=i;
                array[1]=hash_table[mid];
                break;
            }
            hash_table[nums[i]]=i;
        } 

        return array;
        
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>output;
        unordered_map<int,int>hash;
        for (int i=0;i<nums.size();i++)
        {
        hash[nums[i]]=i;
        }

        for (int i=0;i<nums.size();i++)
        {
           int temp=target-nums[i];
           if (hash.count(temp) && hash[temp]!=i)
           {
            output.push_back(i);
            output.push_back(hash[temp]);
            break;
           }
        }
         return output;    }
};

