class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        memset(tree, 0, sizeof(tree));
        
        MAXX = matrix.size();
        MAXY = matrix[0].size();
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++) {
                updateFunc(i+1, j+1, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int sum = sumRegion(row, col, row, col);
        updateFunc(row + 1, col + 1, val-sum );
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = query(row2 + 1, col2 + 1);
        sum -= query(row1, col2 + 1);
        sum -= query(row2 + 1, col1);
        sum += query(row1, col1);
        return sum;
    }

private:
    int tree[305][305];
    int MAXX, MAXY;

    void updateFunc(int x,int y, int val){
        // cout<<MAXX<<" "<<MAXY<<endl;
        int idx = x;
        while(idx <= MAXX){
            int idy = y;
            while(idy <= MAXY){
                tree[idx][idy] += val;
                idy += idy & (-idy);
            }
            idx += idx & (-idx);
        }
        return;
    }
    
    int query(int x,int y){
        int idx = x, sum=0;
        while(idx >0 ){
            int idy = y;
            while(idy > 0){
                sum += tree[idx][idy];
                idy -= idy & (-idy);
            }
            idx -= idx & (-idx);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
