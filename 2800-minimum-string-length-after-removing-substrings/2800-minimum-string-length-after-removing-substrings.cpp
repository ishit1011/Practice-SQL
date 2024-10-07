class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(char ch : s){
            if(st.empty()){
                st.push(ch);
                continue;
            }
            if((st.top() == 'A' && ch == 'B') || (st.top() == 'C' && ch == 'D')){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        int ans = 0;
        while(!st.empty()){
            st.pop();
            ans++;
        }
        return ans;
    }
};