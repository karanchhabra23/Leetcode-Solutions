class LRUCache {
public:
    list<int>l;
    unordered_map<int,list<int>::iterator>m;
    unordered_map<int,int>mp;
    int c;
    
    LRUCache(int capacity) {
        m.clear();
        mp.clear();
        c = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;

        l.erase(m[key]);
        l.push_front(key);
        m[key] = l.begin();
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            l.erase(m[key]);
            m.erase(key);
            mp.erase(key);
        }
        else if(mp.size()==c){
            int x = l.back();
            l.pop_back();
            m.erase(x);
            mp.erase(x);
        }
        
        l.push_front(key);
        mp[key] = value;
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */