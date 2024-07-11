class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string curr = "";

        for (char ch : s) {
            if (ch == '(') {
                stk.push(curr);
                curr = "";
            } else if (ch == ')') {
                reverse(curr.begin(), curr.end());
                if (!stk.empty()) {
                    curr = stk.top() + curr;
                    stk.pop();
                }
            } else {
                curr += ch;
            }
        }

        return curr;
    }
};
