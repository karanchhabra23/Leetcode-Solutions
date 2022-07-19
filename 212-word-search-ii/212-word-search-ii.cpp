class Solution {
public:

    struct TrieNode {
        map<char, TrieNode*>children;
        bool flag = false;
    };

    TrieNode* root;
    vector<vector<char>>board;
    vector<vector<bool>>visited;
    vector<int>dx = {0, 0, -1, 1};
    vector<int>dy = {1, -1, 0, 0};
    int n, m;
    set<string>res;

    bool good(const int x, const int y) {
        if(x < 0 || x >= n || y < 0 || y >= m) return false;
        return true;
    }

    void insertNode(string &str) {
        TrieNode* temp = root;
        for(char &ch: str) {
            if(!temp->children.count(ch)) {
                temp->children[ch] = new TrieNode();
            }
            temp = temp->children[ch];
        }
        temp->flag = true;
    }


    void dfs(TrieNode* root, int x, int y, string &curr) {
        curr.push_back(board[x][y]);
        visited[x][y] = true;
        if(root->flag) {
            res.insert(curr);
        }
        for(int i = 0; i<4; i++) {
            int n_x = x + dx[i];
            int n_y = y + dy[i];
            if(good(n_x, n_y) and !visited[n_x][n_y]) {
                if(root->children.count(board[n_x][n_y])) {
                    dfs(root->children[board[n_x][n_y]], n_x, n_y, curr);
                }
               
            }
        }
        visited[x][y] = false;
        curr.pop_back();
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        this->board = board;
        n = board.size(), m = board[0].size();

        for(string &str: words) {
            insertNode(str);
        }

        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(root->children.count(board[i][j])) {
                   
                    string str = "";
                    dfs(root->children[board[i][j]], i, j, str);
                }
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};