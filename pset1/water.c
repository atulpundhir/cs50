/**
 * Author : Atul Pundhir
 * Description: Program to check the number of water bottles used for x minute of shower
 */

#include <stdio.h>
#include <cs50.h>

//prototype
int getBottles(float minutes);

int main(void){
    printf("minutes: ");
    float minutes_shower = GetFloat();
    int bottles = getBottles(minutes_shower);
    printf("bottles: %i\n", bottles);
}

/**
 * Function to calculate bottles based on Minutes
 */
int getBottles(float minutes){
    return (1.5 * 128 * minutes) / 16;
}