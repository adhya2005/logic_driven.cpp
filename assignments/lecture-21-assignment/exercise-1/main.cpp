#include <iostream>
#include <ucm_random>

using namespace std;

bool allSame(int dice[], int size){
    int first = dice[0];
    for (int i = 1; i < size; i++){
        if (dice[i] != first){
            return false;
        }
    }
    return true;
}

void printDice(int dice[], int size){
    for (int i = 0; i < size; i++){
        cout << ".-------. " ;
    }
    cout << endl;
    
    for (int i = 0; i < size; i++){
        if (dice[i] == 1){
            cout << "|       | " ;
        }
        else if (dice[i] == 2 || dice[i] == 3){
            cout << "| *     | " ;
        }
        else{
            cout << "| *   * | " ;
        }
    }
    cout << endl;

    for (int i = 0; i < size; i++){
        if (dice[i] == 1 || dice[i] == 3 || dice[i] == 5){
            cout << "|   *   | " ;
        }
        else if (dice[i] == 2 || dice[i] == 4){
            cout << "|       | " ;
        }
        else{
            cout << "| *   * | " ;
        }
        
    }
    cout << endl;

    for (int i = 0; i < size; i++){
        if (dice[i] == 1){
            cout << "|       | " ;
        }
        else if (dice[i] == 2 || dice[i] == 3){
            cout << "|     * | " ;
        }
        else{
            cout << "| *   * | " ;
        }
        
    }
    cout << endl;

    for (int i = 0; i < size; i++){
        cout << ".-------. " ;
    }
    cout << endl;
}

int main(){
    
    // Your code here
    RNG generator;
    int size = 2;

    int hand[size];

    string c;

    int score = 0;

    while (true){
        system("clear");
        
        for (int i = 0; i < size; i++){
            hand[i] = generator.get(1, 6);
            score = score + hand[i];
        }

        printDice(hand, size);

        cout << "Current Score: " << score << endl << endl;


        if (allSame(hand, size)){
            score = 0;
            break;
        }

        cout << "Continue ([Y]/N): ";
        getline(cin, c);

        if (toupper(c[0]) == 'N'){
            break;
        }
    }

    cout << "Your score: " << score << endl; 

    return 0;
}