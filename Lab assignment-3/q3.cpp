// 3. Write a program that checks if an expression has balanced parentheses:

#include <iostream>
#include <stack>
using namespace std;

bool check(string s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
      
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) return false; 

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false; 
            }
        }
    }

    return st.empty();
}

int main() {
    string s;
    cout << "Enter an expression: ";
    getline(cin, s);

    if (check(s)) {
        cout << "The expression has balanced parenthesis";
    } else {
        cout << "The expression does NOT have balanced parenthesis";
    }
}
