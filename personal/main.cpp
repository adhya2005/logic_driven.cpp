#include <iostream>

using namespace std;

int main(){

    //char array[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int count[26];

    string word;
    getline(cin, word);

    for (int i = 0; i < 26; i++){
        count[i] = 0;
    }

    for (int i = 0; i < word.length() + 1; i++){
        //for (int j = 0; j < 26; i++){
            int indLetter = char(tolower(word[i]));
            if (indLetter < 'a') {
                cout << "Invalid letter received - " << indLetter << endl;
                break;
            }
            else
            if (indLetter > 'z') {
                cout << "Invalid letter received - " << indLetter << endl;
                break;
            }
            else
            {
                count[indLetter-97]++;
                cout << "valid letter received - " << indLetter << endl;
            }
        //}
    }

    for (int i = 0; i < 26; i++){
        char ch = i+97;
        cout <<  ch << " - " << count[i] << endl;
    }

    return 0;
}

