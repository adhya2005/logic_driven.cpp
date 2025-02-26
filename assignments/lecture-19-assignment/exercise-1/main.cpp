#include <iostream>
#include "ucm_arrays.h"
using namespace std;



int main() {
    float grades[8] = {58, 94, 60, 25, 28, 27, 17, 18};
    float avg = average(grades, 8);

    cout << avg << endl;

    return 0;
}

