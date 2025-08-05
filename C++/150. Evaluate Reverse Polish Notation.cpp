class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values;
        int med_value;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                med_value = values.top();
                values.pop();
                med_value += values.top();
                values.pop();
                values.push(med_value);
            }

            else if (tokens[i] == "-") {
                med_value = values.top();
                 values.pop();
                med_value =values.top() - med_value;
                values.pop();
                values.push(med_value);
            }

            else if (tokens[i] == "*") {
                med_value = values.top();
                 values.pop();
                med_value =values.top() * med_value;
                values.pop();
                values.push(med_value);
            }

            else if (tokens[i] == "/") {
                med_value = values.top();
                 values.pop();
                med_value = values.top() / med_value;
                values.pop();
                values.push(med_value);
            } else {
                values.push(stoi(tokens[i]));
            }
        }
        return values.top();
    }
};