#include <igloo/igloo.h>
#include "ucm_arrays.h"

using namespace igloo;

Context(TextProgram){
    Spec(Test1Coldest){
        const int size = 12;
        float weather[size] = {62.5, 65.3, 71.7, 73.5, 82.4, 96.2, 99.8, 99.2, 91.8, 81.8, 71.9, 64.3};
        Assert::That(coldestMonthIndex(weather, size), Equals(0));
    }
    Spec(Test1Hottest){
        const int size = 12;
        float weather[size] = {62.5, 65.3, 71.7, 73.5, 82.4, 96.2, 99.8, 99.2, 91.8, 81.8, 71.9, 64.3};
        Assert::That(hottestMonthIndex(weather, size), Equals(6));
    }
    Spec(Test2Coldest){
        const int size = 12;
        float weather[size] = {63.5, 64.3, 72.7, 75.5, 85.4, 99.2, 99.8, 100.6, 93.8, 84.8, 75.9, 60.3};
        Assert::That(coldestMonthIndex(weather, size), Equals(11));
    }
    Spec(Test2Hottest){
        const int size = 12;
        float weather[size] = {63.5, 64.3, 72.7, 75.5, 85.4, 99.2, 99.8, 100.6, 93.8, 84.8, 75.9, 60.3};
        Assert::That(hottestMonthIndex(weather, size), Equals(7));
    }
};



int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}

