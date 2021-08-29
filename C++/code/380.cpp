class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        size = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        v.push_back(val);
        mp[val] = size++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        int idx = mp[val];
        swap(v[idx], v[size - 1]);
        v.pop_back();
        size--;
        mp[v[idx]] = idx;
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int random = rand() % size;
        return v[random];
    }
    
    vector<int> v;
    unordered_map<int, int> mp;
    int size;    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */