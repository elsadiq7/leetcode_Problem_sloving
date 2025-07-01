#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashTable;
        stack<int> my_stack;
        int num2_size = nums2.size();
        for (int i = 0; i < num2_size; i++) {
            hashTable[nums2[i]] = i;
        }
        vector<int> result(num2_size, -1);
        vector<int> result2(nums1.size(), -1);
        result=nest_greater_stack(nums2);
        for (int i = 0; i < nums1.size(); i++) {
            int index = hashTable[nums1[i]];
            result2[i]=result[index];
        }
        return result2;
    }
    vector<int> nest_greater_stack(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        for (int i = n - 1; i > -1; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(nums[i]);
        }

        return result;
    }
};

