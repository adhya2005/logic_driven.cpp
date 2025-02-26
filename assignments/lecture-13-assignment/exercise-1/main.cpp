#include <iostream>
#include <ucm_random>
using namespace std;

int main() {

    RNG generator;

    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n; i++){
        int y = generator.get(a, b);
        cout << y << endl;
    }

	return 0;
}