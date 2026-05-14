class Solution {
public:
    void failure(string p,vector<int>& fail){
        int q=0;

        for(int i=1;i<p.size();i++){
            while(q>0 && p[i]!=p[q]) 
                q=fail[q-1];
            
            if(p[i]==p[q])
                q++;
            
            fail[i]=q;
        }
        return;
    }
    
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;
        vector<int>fail(needle.size(),0);
        failure(needle,fail);
        
        int q=0;
        for(int i=0;i<haystack.size();i++){
            while(q>0 && haystack[i]!=needle[q])
                q=fail[q-1];
            
            if(haystack[i]==needle[q])
                q++;
            
            if(q==needle.size())
                return i-needle.size()+1;
        }
        return -1;
        
    }
};