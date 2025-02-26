#include <igloo/igloo.h>
#include "ucm_arrays.h"

using namespace igloo;


Context(TextProgram){
    Spec(Ten){
        float grades[10] = {64, 94, 40, 59, 100, 24, 6, 16, 28, 1};
        float avg = average(grades, 10);
        Assert::That(avg, EqualsWithDelta(43.2, 0.1));
    }
    Spec(Nine){
        float grades[9] = {24, 85, 40, 72, 11, 89, 60, 68, 35};
        float avg = average(grades, 9);
        Assert::That(avg, EqualsWithDelta(53.77, 0.1));
    }
    Spec(Eight){
        float grades[8] = {58, 94, 60, 25, 28, 27, 17, 18};
        float avg = average(grades, 8);
        Assert::That(avg, EqualsWithDelta(40.87, 0.1));
    }
    Spec(Seven){
        float grades[7] = {5, 65, 95, 74, 32, 98, 96};
        float avg = average(grades, 7);
        Assert::That(avg, EqualsWithDelta(66.42, 0.1));
    }
    Spec(Six){
        float grades[6] = {45, 92, 14, 95, 3, 67};
        float avg = average(grades, 6);
        Assert::That(avg, EqualsWithDelta(52.66, 0.1));
    }
    Spec(Five){
        float grades[5] = {83.6, 66.9, 77.1, 28.8, 70.2};
        float avg = average(grades, 5);
        Assert::That(avg, EqualsWithDelta(65.32, 0.1));
    }
    Spec(Four){
        float grades[4] = {74.7, 14.2, 22.1, 90.9};
        float avg = average(grades, 4);
        Assert::That(avg, EqualsWithDelta(50.47, 0.1));
    }
    Spec(Three){
        float grades[3] = {34.9, 78.3, 56.8};
        float avg = average(grades, 3);
        Assert::That(avg, EqualsWithDelta(56.66, 0.1));
    }
    Spec(two){
        float grades[2] = {67.5, 72.4};
        float avg = average(grades, 2);
        Assert::That(avg, EqualsWithDelta(69.95, 0.1));
    }
    Spec(One){
        float grades[1] = {94.6};
        float avg = average(grades, 1);
        Assert::That(avg, EqualsWithDelta(94.6, 0.1));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}