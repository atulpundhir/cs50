/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if(value < 0){
        return false;
    }
    // iterate n numbers and if value found return true
    for(int i=0; i < n; i++){
        if(value == values[i]){
            return true;
        }        
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int tmp=0;
    //outer loop for Bubble sort.
    for(int i=0; i < n; i++){
        for(int j=i+1; j<n; j++){
            // swap values if j is smaller than i
            if(values[j] < values[i]){
                tmp = values[i];
                values[i] = values[j];
                values[j] = tmp;
            }
        }
        printf("%i\n", values[i]);
    }
}