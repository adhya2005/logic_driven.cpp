#include <iostream>
#include <ucm_random>

using namespace std;


int main() {

    RNG generator;

    // Get 2 random ints [1..20]
    int x = generator.get(1, 20);
    int y = generator.get(1, 20);

    // Make sure x is always the bigger 1
    if (x < y){
        int temp = x;
        x = y;
        y = temp;
    }

    // Decide which math operation to perform
    int opCode = generator.get(1, 4);

    int expected;
    string symbol;
    // Display the question
    if (opCode == 1){
        cout << x << " + " << y << " = ";
        expected = x + y;
        symbol = "+";
    }
    if (opCode == 2){
        cout << x << " - " << y << " = ";
        expected = x - y;
        symbol = "-";
    }
    if (opCode == 3){
        cout << x << " * " << y << " = ";
        expected = x * y;
        symbol = "*";
    }
    if (opCode == 4){
        cout << x << " / " << y << " = ";
        expected = x / y;
        symbol = "/";
    }

    // Get the answer from the user
    int answer;
    cin >> answer;

    if (answer == expected){
        cout << "That is the correct answer!" << endl;
    }
    else {
        cout << "That's incorrect. " << x << " " << symbol << " " << y << " = " << expected << endl;
    }

    
    
    return 0;
}

    
