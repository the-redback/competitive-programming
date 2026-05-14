class Solution {
public:
    struct node {
        bool endmark;
        string word;
        node* next[26];

        node() {
            endmark = false;
            word = "";
            for (int i = 0; i < 26; i++)
                next[i] = nullptr;
        }
    };

    node* root = new node();

    void insert(string s) {
        node* curr = root;
        for (auto ch : s) {
            int id = ch - 'a';
            if (curr->next[id] == nullptr)
                curr->next[id] = new node();
            curr = curr->next[id];
        }

        curr->endmark = true;
        curr->word = s;
    }

    vector<string> ans;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int R, C;

    void dfs(vector<vector<char>>& board, int x, int y, node* curr) {
        if (curr->endmark) {
            ans.push_back(curr->word);
            curr->endmark = false;
        }

        char temp = board[x][y];
        board[x][y] = '#';

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || yy < 0 || xx >= R || yy >= C || board[xx][yy] == '#')
                continue;

            int id = board[xx][yy] - 'a';

            if (curr->next[id] != nullptr)
                dfs(board, xx, yy, curr->next[id]);
        }

        board[x][y] = temp;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto s : words) {
            insert(s);
        }

        R = board.size();
        C = board[0].size();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int id = board[i][j] - 'a';
                if (root->next[id] != nullptr) {
                    dfs(board, i, j, root->next[id]);
                }
            }
        }

        return ans;
    }
};