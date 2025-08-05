class Solution {
public:
    bool isValid(string s) {
        stack<char> my_stack;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[')
                my_stack.push(ch);
            else {
                if (my_stack.empty() || 
                    (ch == ')' && my_stack.top() != '(') || 
                    (ch == '}' && my_stack.top() != '{') || 
                    (ch == ']' && my_stack.top() != '['))
                    return false;
                
                my_stack.pop();
            }
        }
        return my_stack.empty();
    }
};