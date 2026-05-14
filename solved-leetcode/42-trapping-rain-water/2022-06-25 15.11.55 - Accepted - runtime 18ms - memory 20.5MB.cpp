class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left(height.size(),0),right(height.size(),0);
        
        left[0]=0;
        for(int i=1;i<height.size();i++){
            left[i]=max(height[i-1],left[i-1]);
        }
        
        right[height.size()-1]=0;
        for(int i=height.size()-2;i>=0;i--){
            right[i]=max(height[i+1],right[i+1]);
        }
        
        int ans=0;
        for(int i=1;i<height.size()-1;i++){
            int k=min(left[i],right[i]);
            if(k>height[i])
                ans+=k-height[i];
        }
        return ans;
    }
};