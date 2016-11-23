/**
 * Author : Atul Pundhir
 * Description: Program for Vigenere Encryption
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int isCapsOrSmall(int arg);
char caesar(char character, int shift, bool isCaps);

int main(int argc, string argv[]){
    if(argc == 2){
        string key = argv[1];
        for(int l=0, klen=strlen(key); l<klen; l++){
            bool result = isalpha(key[l]);
            if(!result){
                printf("Keyword must only contain letters A-Z and a-z\n");
                return 1;
            }
        }
        string str = GetString();
        for(int i=0, j=0, len=strlen(str), keylegnth = strlen(key); i<len; i++){
            int res = isCapsOrSmall(str[i]);
            if(res == 1 || res == 0){
                int mod = j % keylegnth;
                int shift = (int)toupper(key[mod]) - 65;
                char val = caesar(str[i], shift, res); 
              // printf("%c -->, %i --> , %i -->, %i --> %c\n", str[i], str[i], mod, shift, val);
               j++;
               
                printf("%c",val);
            }else{
                printf("%c",str[i]);
            }
          //  char val = caesar(str[i], shift, res); 
           // printf("%c -->, %i --> , %i -->, %i --> %c\n", str[i], str[i], mod, shift, val);
           // printf("%c", val);
           
        }
        printf("\n");
    }else{
        printf("Usage: /home/ubuntu/workspace/pset2/vigenere <key>\n");
        return 1;
    }
    
}

char caesar(char character, int shift, bool isCaps){
    if(isCaps == 1){
        int delta = (int)character+shift;
        if(delta > 90){
            // -1 needed for right calculation for the key difference
            int k = (65 + (delta - 90)) - 1;
            return k;
        }else{
            return delta;
        }
    }else if(isCaps == 0){
       int delta = (int)character+shift;
        if(delta > 122){
            // -1 needed for right calculation for the key difference
            int k = (97 + (delta - 122)) - 1;
            return k;
        }else{
            return delta;
        }
    }
    return false;
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