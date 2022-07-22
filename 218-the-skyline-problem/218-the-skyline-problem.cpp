class Solution {
 public:
    vector<int>tree;
    vector<int>lazy;
    unordered_map<int,int>m;

    void update(int node, int start, int end, int l, int r,int val){
        if(lazy[node]!=0){
            int dx = lazy[node];
            lazy[node] = 0;
            tree[node] = max(tree[node],dx);
            if(start!=end){
                lazy[2*node] = max(lazy[2*node],dx);
                lazy[2*node+1] = max(lazy[2*node+1],dx);
            }
        }
        if(start>r || end<l || start>end){
            return;
        }
        if(start>=l && end<=r){
            int dx = val;
            tree[node] = max(tree[node],dx);
            if(start!=end){
                lazy[2*node] = max(lazy[2*node],dx);
                lazy[2*node+1] = max(lazy[2*node+1],dx);
            }

            return ;
        }
        int mid = start + (end - start) / 2;
        update(2*node,start,mid,l,r,val);
        update(2*node+1,mid+1,end,l,r,val);
        tree[node] = max(tree[2*node],tree[2*node+1]);
    }

    int query(int node, int start, int end, int ind){
        if(lazy[node]!=0){
            int dx = lazy[node];
            lazy[node] = 0;
            tree[node] = max(tree[node],dx);
            if(start!=end){
                lazy[2*node] = max(lazy[2*node],dx);
                lazy[2*node+1] = max(lazy[2*node+1],dx);
            }
        }
        if(start==end){
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if(ind<=mid){
            return query(2*node,start,mid,ind);
        }
        else{
            return query(2*node+1,mid+1,end,ind);
        }

    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<int>st;
        for(auto &it:buildings){
            st.insert(it[0]);
            st.insert(it[1]);
        }
        int x = st.size();
        vector<int>debug(x+1);
        int idx = 1;
        for(auto &it:st){
            debug[idx] = it;
            m[it] = idx;
            idx++;
        }
        tree.resize(4*(x + 1) +10,0);
        lazy.resize(4*(x + 1) + 10,0);
        vector<vector<int>>ans;
        // build(1,1,idx);
        for(auto &it:buildings){
            update(1,1,idx-1,m[it[0]],m[it[1]]-1,it[2]);
        }
        for(int i = 1;i<idx;i++){       
            int r = query(1,1,idx-1,i);
            if(ans.size() && ans.back()[1]==r ){
                continue;
            }
            ans.push_back({debug[i],query(1,1,idx-1,i)});
        }
        return ans;
    }

};