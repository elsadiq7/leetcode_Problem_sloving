class Solution {
public:
    int calculate(string s) {
        stack<int> nums;  // To hold previous results
        stack<int> ops;   // To hold signs (+1 or -1)
        int result = 0;
        int sign = 1;
        int num = 0;

        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = ch - '0';
                while (i + 1 < s.length() && isdigit(s[i + 1])) {
                    num = num * 10 + (s[++i] - '0');
                }
                result += sign * num;
            } else if (ch == '+') {
                sign = 1;
            } else if (ch == '-') {
                sign = -1;
            } else if (ch == '(') {
                nums.push(result);
                ops.push(sign);
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                result = nums.top() + ops.top() * result;
                nums.pop();
                ops.pop();
            }
        }

        return result;
    }
};
