// contatenate:
#include<iostream>
#include<string>
using namespace std;

int main() {
  string s1, s2;
  cout << "Enter first string: ";
  cin >> s1;
  cout << "Enter second string: ";
  cin >> s2;
  cout << "Result: " << s1+s2;
}

// reverse:
#include<iostream>
#include<string>
using namespace std;

int main() {
  string s;
  cout << "Enter string: ";
  cin >> s;
  for(int i=s.size()-1; i>=0; i--)
    cout << s[i];
}

// deleting vowels:
#include<iostream>
#include<string>
using namespace std;

int main() {
  string s, r="";
  cout << "Enter string: ";
  cin >> s;

  for(int i=0; i<s.size(); i++) {
    if(!(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
         s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'))
      r += s[i];
  }
  cout << r;
}

// sorting the strings in alphabetical order:
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
  string arr[5];
  cout << "Enter 5 strings: ";
  for(int i=0; i<5; i++) cin >> arr[i];

  sort(arr, arr+5);

  cout << "Sorted: ";
  for(int i=0; i<5; i++) cout << arr[i] << " ";
}


// uppercase to lowercase:
#include<iostream>
#include<cctype>
using namespace std;

int main() {
  char c;
  cout << "Enter character: ";
  cin >> c;
  cout << "Lowercase: " << (char)tolower(c);
}
