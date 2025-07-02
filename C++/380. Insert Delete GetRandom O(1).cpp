class RandomizedSet {
private:
    unordered_map<int, int> hash;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (hash.count(val))
            return false;
        else {
            hash[val] = val;
            return true;
        }
    }

    bool remove(int val) {
        if (hash.count(val)) {
            hash.erase(val);
            return true;
        }

        else
            return false;
    }

    int getRandom() {
        if (hash.empty())
            return 0;
        auto it = hash.begin();
        std::advance(it, rand() % hash.size());
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

 //link:https://leetcode.com/problems/insert-delete-getrandom-o1/?envType=study-plan-v2&envId=top-interview-150