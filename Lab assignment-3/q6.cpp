// infix to prefix:
#include<iostream>
#include<stack>
#include<cctype>
#include<algorithm>
using namespace std;

int precedence(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/' || c=='%') return 2;
    else if(c=='+' || c=='-') return 1;
    return 0;
}

// Function to reverse string and swap ( , )
string reverseStr(string s){
    reverse(s.begin(), s.end());   // reverse whole string
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    return s;
}

// Infix to Postfix
string in_to_post(string s){
    stack<char> st;
    string post="";

    for(int i=0; i<s.length(); i++){
        if(isalnum(s[i])){          // operand
            post+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                post+=st.top();
                st.pop();
            }
            st.pop(); // pop '('
        }
        else{ // operator
            while(!st.empty() && precedence(s[i])<=precedence(st.top())){
                post+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        post+=st.top();
        st.pop();
    }
    return post;
}

int main(){
    string s;
    cout<<"Enter the infix expression: ";
    getline(cin,s);

    // Step 1: reverse infix and swap brackets
    string x = reverseStr(s);

    // Step 2: convert to postfix
    string poost = in_to_post(x);

    // Step 3: reverse postfix to get prefix
    string prefix = reverseStr(poost);

    cout<<"The prefix expression is: "<<prefix<<endl;

    return 0;
}
