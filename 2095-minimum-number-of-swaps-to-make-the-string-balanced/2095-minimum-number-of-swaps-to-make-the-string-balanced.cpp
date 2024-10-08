class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        for(char ch : s){
            if(!stk.empty()){
                if(ch == ']' && stk.top() == '['){
                    stk.pop();
                    continue;
                }
            }
            stk.push(ch);
        }
        int cntClosed = 0;
        while(!stk.empty()){
            if(stk.top() == ']'){
                cntClosed++;
            }
            stk.pop();
        }
        return (cntClosed+1)/2; 
    }
};