#include <iostream>
using namespace std;

int main() {
	
	float price;
    bool membership;
    cin >> price >> membership;

    if (price >= 1000){
        cout << "Free shipping" << endl;
    }
    else{
        if (membership == true){
            cout << "Discounted shipping" << endl;
        }
        else{
            cout << "Full price shipping" << endl;
        }
    }

    return 0;
}