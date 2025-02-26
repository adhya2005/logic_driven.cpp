#include <iostream>
using namespace std;

int main() {
    
   string s;
   getline(cin, s);

   for (int i = 0; i < s.length(); i++){
       if (s[i] == 'a'){
           s[i] = '@';
           
       }
       else if (s[i] == 'c'){
           s[i] = '(';
           
       }
       else if (s[i] == 'g'){
           s[i] = '9';
           
       }
       else if (s[i] == 'o'){
           s[i] = '0';
           
       }
       else if (s[i] == 's'){
           s[i] = '$';
       } 
   }
   cout << s << endl;

    return 0;
}