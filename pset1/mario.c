/**
 * Author : Atul Pundhir
 * Description: Program to Print Mario Pyramid based on user input
 */

#include <stdio.h>
#include <cs50.h>

int main(void){
    int n = 0;
    
    // input validation
    do{
        printf("Height: ");
        n = GetInt();
    }while(n < 0 || n > 23);
    
    
    // outer loop to print rows
    for(int i=1; i<=n; i++){
        // inner loop to print spaces
        for(int k=n-i; k>=1; k--){
            printf(" ");
        }
       
        // inner loop to print #
        for(int l=0; l<=i; l++){
            printf("#");
        }
        printf("\n");
    }
}