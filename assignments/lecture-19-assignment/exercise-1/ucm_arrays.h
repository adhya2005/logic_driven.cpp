#ifndef UCM_ARRAYS_H
#define UCM_ARRAYS_H

float average(float arr[], int size){
    float average = 0;
    float total = 0;
    for (int i = 0; i < size; i++){
       total += arr[i];
    }
    average = total/size;

    return average;
}

#endif