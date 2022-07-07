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
    vector<node*>m;
    int c;
    int sz;
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
        m = vector<node*>(10001,NULL);
        head->next = tail;
        tail->prev = head;
        sz = 0 ;
    }
    
    int get(int k) {
        if(m[k]!=NULL){
            node* temp = m[k];
            int v = temp->value;
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
        if(m[k]!=NULL){
            node* exist = m[k];
            // m[k]=NULL;
            del(exist);
            sz--;
        }
        else if(sz==c){
            node* temp = tail->prev;
            m[temp->key] = NULL;
            // m.erase(temp->key);
            del(temp);
            sz--;
            // sz--;
        }
        
        add(new node(k,v));
        m[k] = head->next;
        sz++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */