/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

//Global state for blank
int blankPos1;
int blankPos2;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int startBoard = (d*d) -  1;
    for(int i=0; i<d; i++){
        for(int j=0; j<d;j++){
            board[i][j] = startBoard--;
        }
    }
    
    if((d*d) % 2 == 0){
        board[d-1][d-2] = 2;
        board[d-1][d-3] = 1;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // iterate rows
    for(int i=0; i<d; i++){
        // iterate cols
        for(int j=0; j<d;j++){
            if(board[i][j] != 0){
                printf("%i\t", board[i][j]);    
            }else{
                blankPos1 = i;
                blankPos2 = j;
                printf("%c\t", '_');
            }
            
        }
        printf("\n");
    }
   usleep(2000000);  
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int pos1;
    int pos2;
    // iterate rows
    for(int i=0; i<d; i++){
        // iterate cols
        for(int j=0; j<d;j++){
            // set position 
            if(board[i][j] == tile){
                pos1 = i;
                pos2 = j;
            }
        }
    }
    
    // check whether its a valid move or not
   if((board[blankPos1-1][blankPos2] == tile) || (board[blankPos1][blankPos2-1] == tile) || (board[blankPos1+1][blankPos2] == tile) || (board[blankPos1][blankPos2+1] == tile)){
    
        board[pos1][pos2] = 0;
        board[blankPos1][blankPos2] = tile;
        
        blankPos1 = pos1;
        blankPos2 = pos2;
        return true;
   }else{
       return false;
   }
    
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int cnt = 1;
    
    // iterate over rows
    for(int i=0; i<d; i++){
        // iterate over columns
        for(int j=0; j<d;j++){
            // check if value of counter matches with board value and less than total elements, if not returl false
            if(board[i][j] != cnt && cnt < (d*d)){
                return false;    
            }
            
            cnt++;
        }
    }
       
    
    return true;
}