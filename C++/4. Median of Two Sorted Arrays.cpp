class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums=mergeSortedArrays(nums1,nums2);
        int size=nums.size();
        double median;
        if(size%2==0)
        {
           median=(nums[size/2]+nums[size/2-1])/2.0;
        }
        else
          median=nums[size/2];
        
        return median;

    }

    vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    int i = 0, j = 0;
    vector<int> merged;

    // Traverse both arrays
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    // Add remaining elements of arr1
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }

    // Add remaining elements of arr2
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}
};