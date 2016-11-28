/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(void)
{
    FILE* file = fopen("card.raw", "r");
    
    if(file == NULL){
        printf("Not a valid file, Can not recover");
        return 1;
    }
    
    BYTE buffer[512];
    
    FILE* new_file = NULL;
    
    char fname[10];
    
    int cnt=0;
    
    while(!feof(file)){
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xef)){
            
            sprintf(fname, "%03d.jpg", cnt);
            new_file = fopen(fname, "w");
            fwrite(buffer, sizeof(buffer), 1, new_file);
            cnt++;
        }
        else if(cnt > 0){
            fwrite(buffer, sizeof(buffer), 1, new_file);
        }
       
        fread(buffer, sizeof(buffer), 1, file);
    }
    
    fclose(file);
    
    return 0;
}
