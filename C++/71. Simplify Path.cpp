#include <sstream>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stack<std::string> st;
        std::vector<std::string> tokens;
        std::stringstream ss(path);
        std::string token;

        // Step 1: Split the path by '/'
        while (getline(ss, token, '/')) {
            tokens.push_back(token);
        }

        // Step 2: Process each token
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "" || tokens[i] == ".") {
                continue;
            } else if (tokens[i] == "..") {
                if (!st.empty())
                    st.pop();
            } else {
                // Clean any slashes inside the token (optional, usually not
                // needed)
                std::string str = "";
                for (char ch : tokens[i]) {
                    if (ch != '/') {
                        str += ch;
                    }
                }
                if (!str.empty())
                    st.push(str);
            }
        }

        std::string final_path = "";
        vector<string> reversed;
        while (!st.empty()) {
            reversed.push_back(st.top());
            st.pop();
        }

        for (int i = reversed.size() - 1; i >= 0; i--) {
            final_path += "/" + reversed[i];
        }

        return final_path.empty() ? "/" : final_path;
    }
};
