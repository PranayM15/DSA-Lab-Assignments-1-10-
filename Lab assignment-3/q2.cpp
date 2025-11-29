// reverse a string using stack:

#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s;
    cout<<"Enter the string to be reversed: ";
    getline(cin,s);
    stack<char> s1;
    for(int i=0;i<s.size();i++){
        s1.push(s[i]);
    }
    cout << "Reversed string: ";
    // Pop and print characters
    while (!s1.empty()) {
        cout << s1.top();
        s1.pop();
    }
    cout << endl;
    
}