#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void){
    string str = GetString();
    for(int i=0; i<strlen(str); i++){
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