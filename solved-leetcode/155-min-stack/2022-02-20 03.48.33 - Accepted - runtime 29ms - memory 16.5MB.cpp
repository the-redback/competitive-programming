class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        Node* nw=new Node(val);
        nw->prev=last;
        last=nw;
        if(nw->prev!=NULL && nw->prev->min < val)
            nw->min=nw->prev->min;
        else
            nw->min=val;
    }
    
    void pop() {
        Node* tmp=last;
        last=last->prev;
        delete(tmp);
    }
    
    int top() {
        return last->val;
    }
    
    int getMin() {
        return last->min;
    }
private:
    struct Node{
        int val;
        int min;
        Node* prev;
        Node(){val=0;min=INT_MAX;prev=NULL;}
        Node(int v){val=v;min=INT_MAX;prev=NULL;}
    };
    Node* last=NULL;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */