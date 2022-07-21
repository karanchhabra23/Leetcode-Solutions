
class Solution {
public:
struct node{
	node* arr[2];
};


node* root = new node();
	
	void insert(int num){
		node* temp = root;
		for(int i = 31;i>=0;i--){
			int ind;
			if((1<<i) & num){
				ind  = 1;
			}
			else{
				ind = 0;
			}
			if(temp->arr[ind]==NULL){
				temp->arr[ind] = new node();
			}
			temp = temp->arr[ind];
		}
	}
	

	int getmax(int num){
		node* temp = root;
		int ans = 0;
		for(int i=31;i>=0;i--){
			int ind;
			if((1<<i )& num){
				ind  = 0;
			}
			else{
				ind = 1;
			}
			if(temp->arr[ind]!=NULL){
				temp= temp->arr[ind];
				ans|= (1<<i);
			}
			else{
				temp = temp->arr[1-ind];
			}

		}
		return ans;
	}
	


vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
    vector<vector<int>> offlineQueries; 
    sort(arr.begin(), arr.end()); 
    int index = 0;
    for(auto &it: queries) {
        offlineQueries.push_back({it[1],it[0], index++}); 
    }
	sort(offlineQueries.begin(),offlineQueries.end());
	int n = arr.size();
	int i = 0;
	vector<int>ans(queries.size());
	for(auto &it:offlineQueries){
		while(i<n && arr[i]<= it[0]){
			insert(arr[i]);
			i++;
		}
		
		if(i!=0) ans[it[2]] = getmax(it[1]); 
        else ans[it[2]] = -1; 
		
	}
	return ans;
    }
};