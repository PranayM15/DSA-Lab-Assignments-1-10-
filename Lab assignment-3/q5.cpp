// 5. Write a program for the evaluation of a Postfix expression.

#include<iostream>
#include<stack>
#include<cctype>
#include<cmath>
using namespace std;

int reesult(string s){
    stack<int> st;
    int result;
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if(isdigit(c)){
            st.push(c-'0');
        }
        else{
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            
            switch(c){
                case '+':
                result=y+x; break;
                case '-':
                result = y-x; break;
                case '/':
                result=y/x; break;
                case '*':
                result=y*x; break;
                case '%':
                result=y%x; break;
                case '^':
                result=pow(y,x); break;
            }
            st.push(result);
        }
        
    }
    return st.top();
    
}

int main(){
    string s;
    cout<<"Enter the postfix expression: ";
    getline(cin,s);
    cout<<"The postfix expression's result is: "<<reesult(s);
}