#include <iostream>
#include "ucm_arrays.h"
using namespace std;

int main() {
    const int size = 12;
    float weather[size] = {62.5, 65.3, 71.7, 73.5, 82.4, 96.2, 99.8, 99.2, 91.8, 81.8, 71.9, 64.3};
    string months[size] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "Octover", "November", "December"};

    int hottestIndex = hottestMonthIndex(weather, size);
    int coldestIndex = coldestMonthIndex(weather, size);

    cout << months[coldestIndex] << " had the coldest temperature with an average of " << weather[coldestIndex] << endl;
    cout << months[hottestIndex] << " had the hottest temperature with an average of " << weather[hottestIndex] << endl;
    

    return 0;
}
