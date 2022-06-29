class node{
    public:
    int key;
    int value;
    node* prev;
    node* next;
    node(int k, int v){
        key = k;
        value = v;
    }
    
};
class LRUCache {
public:
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    unordered_map<int,node*>m;
    int c;
    void del(node* n){
        n->next->prev = n->prev;
        n->prev->next = n->next;
    }
    
    void add(node* n){
        node* temp = head->next;
        temp->prev = n;
        n->next = temp;
        head->next = n;
        n->prev = head;
    }
    
    LRUCache(int capacity) {
        c = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int k) {
        if(m.find(k)!=m.end()){
            node* temp = m[k];
            int v = temp->value;
            m.erase(k);
            del(temp);
            add(temp);
            m[k] = head->next;
            return v;
        }
        else{
            return -1;
        }
    }
    
    void put(int k, int v) {
        if(m.find(k)!=m.end()){
            node* exist = m[k];
            m.erase(k);
            del(exist);
        }
        else if(m.size()==c){
            node* temp = tail->prev;
            m.erase(temp->key);
            del(temp);
        }
        
        add(new node(k,v));
        m[k] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */