#ifndef UCM_ARRAYS_H
#define UCM_ARRAYS_H

int hottestMonthIndex(float arr[], int size){
    float max = arr[0];
    int maxPos = 0;

    for (int i = 0; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
            maxPos = i;
        }
    }

    return maxPos;
}

int coldestMonthIndex(float arr[], int size){
    float min = arr[0];
    int minPos = 0;

    for (int i = 0; i < size; i++){
        if (arr[i] < min){
            min = arr[i];
            minPos = i;
        }
    }

    return minPos;
}


#endif