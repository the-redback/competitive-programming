class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sq, tq;

        for(char ch: s){
            if(ch == '#'){
                if(!sq.empty())
                    sq.pop();
            } else {
                sq.push(ch);
            }
        }

        for(char ch: t){
            if(ch == '#'){
                if(!tq.empty())
                    tq.pop();
            } else {
                tq.push(ch);
            }
        }

        while( !sq.empty() && !tq.empty() ){
            if( sq.top() != tq.top() ){
                return false;
            }
            sq.pop();
            tq.pop();
        }

        return sq.empty() && tq.empty();
    }
};