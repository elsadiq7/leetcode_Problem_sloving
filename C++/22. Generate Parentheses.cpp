class Solution {
public:
    vector<string> result;
    string path = "";
    char v[2] = {'(', ')'};
    
    vector<string> generateParenthesis(int n) {
        backtrack(n);
        return result;
    }

    void backtrack(int n) {
        if (path.length() == 2 * n) {
            if (isValid(path)) {
                result.push_back(path); // now vector works
            }
            return;
        }
      
        for (char s : v) {
            path += s;
            backtrack(n);
            path.pop_back();
        }
    }

    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(') st.push(ch);
            else {
                if (st.empty() || st.top() != '(') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
