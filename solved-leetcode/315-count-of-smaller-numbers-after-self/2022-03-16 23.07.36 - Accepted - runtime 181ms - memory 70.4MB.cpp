class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>>v;
        MaxVal = 2 * 1e4 + 20;
        int offset = 1e4 + 10;
        memset(tree, 0, sizeof(tree));
        
        vector<int>ans(nums.size(),0);
        
        for(int i=nums.size()-1; i>=0 ; i--){
            ans[i] = query(nums[i] + offset);
            update(nums[i] + offset + 1, 1);
        }

        return ans;
    }
    
    
int MaxVal;
int tree[100010];
    
    void update(int idx, int val){
        while(idx<=MaxVal){
            tree[idx]+=val;
            idx += idx & (-idx);
        }
    }
    
    int query(int idx){
        int sum=0;
        while(idx>0){
            sum+=tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};


static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);