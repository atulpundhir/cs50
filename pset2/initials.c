/**
 * Author : Atul Pundhir
 * Description: Program to print Initials of names in CAPS
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void){
    //User Input
    string str = GetString();
    
    // Loop through each charaacter
    for(int i=0; i<strlen(str); i++){
        // If to be executed for first character and else if for spaces
        if(i == 0){
            if((int)str[i] >= 97 && (int)str[i] <= 122){
                printf("%c", str[i] - 32);
            }else{
                printf("%c", str[i]);
            }
        }else if((int)str[i] == 32){
            if((int)str[i+1] >= 97 && (int)str[i+1] <= 122 ){
                printf("%c", str[i+1] - 32);
            }else{
                printf("%c", str[i+1]);
            }
        }
    }
    printf("\n");
}