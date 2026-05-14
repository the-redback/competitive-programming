class Solution {
public:
    int candy(vector<int>& ratings) {
        int up = 0, down = 0;
        int ans = ratings.size();

        for(int i = 1; i < ratings.size(); i++){
            
            if(ratings[i] > ratings[ i - 1]){
                if(down) up = down = 0;
                up++;
                ans += up;
            } else if( ratings[i] == ratings[i - 1] ){
                up = down = 0;
            } else{
                if(up == down) 
                    down++;
                ans += down;
                down++;
            }
        }
        return ans;
    }
};


static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);