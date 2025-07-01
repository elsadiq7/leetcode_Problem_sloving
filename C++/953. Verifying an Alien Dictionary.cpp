class Solution {
    public:
        bool isAlienSorted(vector<string>& words, string order) {
            unordered_map<char, int> odrer_map;
    
            for (int i = 0; i < order.length(); i++) {
                odrer_map[order[i]] = i;
            }
            string mid, mid1;
            int size, size1;
            int min_size;
    
            for (int i = 0; i < words.size() - 1; i++) {
                mid = words[i];
                mid1 = words[i + 1];
                size = mid.length();
                size1 = mid1.length();
                bool different = false;
    
                min_size = min(size, size1);
    
                for (int j = 0; j < min_size; j++) {
                    if ((odrer_map[mid[j]] < odrer_map[mid1[j]])) {
                        different = true;
                        break;
                    } else if ((odrer_map[mid[j]] > odrer_map[mid1[j]]))
                        return false;
                }
    
                if (!different && size > size1)
                    return false;
            }
    
            return true;
        }
    };