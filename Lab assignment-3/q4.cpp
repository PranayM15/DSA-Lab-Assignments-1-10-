// 4. Write a program to convert an Infix expression into a Postfix expression.

#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
int precedence(char c){
    
        if(c=='^') return 3;
        else if(c=='*' or c=='/' or c=='%') return 2;
        else if(c=='+' or c=='-') return 1;
        return 0;
    
}

string in_to_post(string s){
    stack<char> st;
    string post="";

   for(int i=0; i<s.length(); i++){
        if(isalnum(s[i])){
            post+=s[i];
        }
        else if(s[i]==' '){
            continue;
        }

        else if(s[i]=='('){
            st.push(s[i]);

        }
        else if(s[i]==')'){
            while(!st.empty() and st.top()!='('){
                post+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() and precedence(s[i])<=precedence(st.top())){
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
    cout<<"The postfix expression is: "<<in_to_post(s);
}