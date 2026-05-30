class Solution {
public:
    bool isValid(string s) {
        stack<char> stick;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{'){
                stick.push(c);
            } else if (!stick.empty()) {
                if (c == ')') {
                    if (stick.top() != '(') {
                        return false;
                    }
                }
                else if (c == '}') {
                    if (stick.top() != '{') {
                        return false;
                    }
                }
                else if (c == ']') {
                    if (stick.top() != '[') {
                        return false;
                    }
                }
                stick.pop();
            } else return false;

        }
        return stick.empty();
    }
};
