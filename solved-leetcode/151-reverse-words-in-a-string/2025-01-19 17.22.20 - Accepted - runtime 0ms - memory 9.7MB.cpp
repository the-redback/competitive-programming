class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int n = s.size();
        int id=0;
        for(int i=0; i<n ; i++){
            if(s[i] == ' ')
                continue;

            if(id != 0)
                s[id++] = ' ';
            
            int end = i;
            int beginId = id;

            while(end<n && s[end] != ' ')
                s[id++] = s[end++];
            
            reverse(s.begin() + beginId, s.begin() + id);
            i=end;
        }
        
        s.erase(s.begin()+id, s.end());
        return s;
    }
};