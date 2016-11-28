/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./rezie factor infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    
    // User input for resize factor
    int factor = atoi(argv[1]);
    
    if(factor < 1 || factor > 100){
        printf("Factor value can only be between 1 to 100");
        return 1;
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER, Also assign same to bf_new variable
    BITMAPFILEHEADER bf, bf_new;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_new = bf;

    // read infile's BITMAPINFOHEADER, Also assign same to bi_new variable
    BITMAPINFOHEADER bi, bi_new;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_new = bi;

    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // calculate the new height and width
    bi_new.biHeight = bi.biHeight * factor;
    bi_new.biWidth = bi.biWidth * factor;
   

    
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding =  (4 - (bi_new.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    
    //New file's size
    bi_new.biSizeImage = (bi_new.biWidth * (int)sizeof(RGBTRIPLE) + new_padding) * abs(bi_new.biHeight);

  //  bi_new.biSizeImage=(bi_new.biWidth+new_padding)*(abs(bi_new.biHeight)*sizeof(RGBTRIPLE));
  
   // bi_new.biSizeImage = (((int)sizeof(RGBTRIPLE) * bi_new.biWidth) + new_padding) * (abs(bi_new.biHeight);
    bf_new.bfSize = bi_new.biSizeImage + 54;
    
  //  bi_new.biSizeImage = (((int)sizeof(RGBTRIPLE) * bi_new.biWidth) + new_padding) * (abs(bi_new.biHeight));
//    bf_new.bfSize = bi_new.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
   // bf_new.bfSize = (int)bf.bfSize - (int)bi.biSizeImage * (int)bi_new.biSizeImage;
    
        // write outfile's BITMAPFILEHEADER
    fwrite(&bf_new, sizeof(BITMAPFILEHEADER), 1, outptr);
   
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_new, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for(int l=0; l<factor; l++){
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                for(int k=0; k < factor; k++){
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
    
            }
            
            for(int m=0; m < new_padding; m++){
                fputc(0x00, outptr);
            }
            
            if(l < factor -1){
               // printf("%lu\n",-bi.biWidth * sizeof(RGBTRIPLE));
                fseek(inptr, -bi.biWidth * (int)sizeof(RGBTRIPLE), SEEK_CUR);
            }
        }
         
        fseek(inptr, padding, SEEK_CUR);     
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
