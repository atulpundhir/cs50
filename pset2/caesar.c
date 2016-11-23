/**
 * Author : Atul Pundhir
 * Description: Program for Caesar Encryption
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>

//prototype
int isCapsOrSmall(int arg);

int main(int argc, string argv[]){
    // User input validation
    if(argc != 1){
        int key = atoi(argv[1]) % 26;
        string str = GetString();
        // loop through the string
        for(int i=0, len=strlen(str) ; i<len; i++){
            // check for character is Capital or small
            int res = isCapsOrSmall(str[i]);
            if(res == 1){
                int delta = (int)str[i]+key;
                if(delta > 90){
                    // -1 needed for right calculation for the key difference
                    int k = (65 + (delta - 90)) - 1;
                    printf("%c",k);
                }else{
                    printf("%c",delta);
                }
            }else if(res == 0){
               int delta = (int)str[i]+key;
                if(delta > 122){
                    // -1 needed for right calculation for the key difference
                    int k = (97 + (delta - 122)) - 1;
                    printf("%c", k);
                }else{
                    printf("%c", delta);
                }
            }else{
                printf("%c", str[i]);
            }
        }
        printf("\n");
    }else{
        printf("Usage: /home/ubuntu/workspace/pset2/caesar <key>\n");
        return 1;
    }
}

// Function to check wether character is CAPS or SMALL
int isCapsOrSmall(int arg){
    if(arg >= 65 && arg <=90){
        return 1;
    }else if(arg >= 97 && arg <=122){
        return 0;
    }else{
        return 2;
    } 
}