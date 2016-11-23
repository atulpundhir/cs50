/**
 * Author : Atul Pundhir
 * Description: Program for Change dispenser 
 */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    float n=0.0;
    int k = 0;
    do{
        printf("O hai! How much change is owed?\n");
        n = GetFloat();   
    }while(n < 0);
    
  
    int cents = round(n * 100);
   
    if(cents >= 25 ){
        k = cents / 25;
        cents = cents % 25;
    }
    
    if(cents >= 10){
        k = k + (cents / 10);
        cents = cents % 10;
    }
    
    if(cents >= 5){
         k = k + (cents / 5);
        cents = cents % 5;
    }
    
    if(cents >= 1){
        for(int i=1;i<=cents;i++){
            k++;
        }
    }
        
    printf("%i\n", k);
    
}