#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char **arr);
void searchPuzzle(char **arr, char *word);
int bSize;
void declarePointer(int order, char *arr);
void printPath(char *word, char **arr, int count);
//declare bunch of char pointers
char *ptr0 = NULL, *ptr1 = NULL, *ptr2 = NULL, *ptr3 = NULL, *ptr4 = NULL, *ptr5 = NULL, *ptr6 = NULL, *ptr7 = NULL, *ptr8 = NULL;

// Main function, DO NOT MODIFY
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);

    // Allocate space for the puzzle block and the word to be searched
    char **block = (char **)malloc(bSize * sizeof(char *));
    char *word = (char *)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for (i = 0; i < bSize; i++)
    {
        *(block + i) = (char *)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j)
        {
            fscanf(fptr, "%c ", *(block + i) + j);
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%s", word);

    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);

    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);

    return 0;
}
//declared
/*
void declarePointer(int order, char *arr)
{
    switch (order)
    {
    case 0:
        ptr0 = arr;
        break; // optional 
    case 1:
        ptr1 = arr;

        break; // optional 
    case 2:
        ptr2 = arr;

        break; // optional 

    case 3:
        ptr3 = arr;

        break; // optional 

    case 4:
        ptr4 = arr;

        break; // optional 

    case 5:
        ptr5 = arr;

        break; // optional 
    case 6:
        ptr6 = arr;

        break; // optional 
    case 7:
        ptr7 = arr;

        break; // optional 
    case 8:
        ptr8 = arr;

        break; // optional 
    }
}
*/

void printPuzzle(char **arr)
{
    // This function will print out the complete puzzle grid (arr).
    // It must produce the output in the SAME format as the samples
    // in the instructions.
    // Your implementation here...

    //printf("size of arr is %lu", sizeof(arr) / 2);

    int size = bSize;

    for (int i = 0; i < size; i++) //accessing rows with i
    {
        for (int j = 0; j < size; j++) //accessing columns with j
        {
            printf("%c ", *(*(arr + i) + j)); // array2D
        }
        printf("\n");
    }
    return;
    //free(size);
}

/*
void printPath(char *word, char **arr, int count)
{
    if (count = 0)
    { //we have reached the end kill program
        return;
    }
    int wordSize = strlen(word); //checks word size
    // printf("%d",wordSize);
    int size = bSize; // size of array rows and columns

    for (int i = 0; i < size; i++) //accessing rows with i
    {
        for (int j = 0; j < size; j++) //accessing columns with j
        {
            if (word[0] == (*(*(arr + i) + j)))
            { //if number is equal print wordsize
                //to label path number;
                printf("0");
            }
            else
            {
                printf("0"); //if number is irrelevant print 0
            }
        }
    }
    count = count - 1;
    printPath(word, arr, count);
    return;
}
*/

void searchLetter(char **arr, char *word)
{
    char *next, *right, *left, *up, *upleft, *upright, *down, *downleft, *downright;
    //char **up = (char **)malloc(3);
    for (int i = 0; i < bSize; i++) //accessing columns with i
    {
        for (int j = 0; j < bSize; j++) //accessing columns with j
        {
            if (*word == *(*(arr + i) + j))
            {
                printf("Found %c at [%d, %d] \n", *word, i, j);
                next = word + 1; //next letter to check
                //printf("this is next %c", *next);
                right = (*(arr + i) + (j + 1));
                left = (*(arr + i) + (j - 1));
                printf("%c LEFT => %c \n", *word, *left);
                printf("%c RIGHT => %c \n", *word, *right);

                up = *(arr + (i - 1)) + j;
                printf("%c UP => %c \n", *word, *up);
                upleft = *(arr + (i - 1)) + (j - 1);
                printf("%c UP-LEFT => %c \n", *word, *upleft);
                upright = *(arr + (i - 1)) + (j + 1);
                printf("%c UP-RIGHT => %c \n", *word, *upright);

                down = *(arr + (i + 1)) + j;
                printf("%c DOWN => %c \n", *word, *down);
                downleft = *(arr + (i + 1)) + (j - 1);
                printf("%c DOWN-LEFT => %c \n", *word, *downleft);
                downright = *(arr + (i + 1)) + (j + 1);
                printf("%c DOWN-RIGHT => %c \n", *word, *downright);

                // switch (*next)
                // {
                // case *left:
                //     printf("these are equal");
                //     break;

                // default:
                //     break;
                // }
                if (*next == *left)
                {
                    printf("left is true \n");
                }
                if (*next == *right)
                {
                    printf("right is true \n");
                }
                if (*next == *up)
                {
                    printf("up is true \n");
                }
                if (*next == *upleft)
                {
                    printf("upleft is true \n");
                }
                if (*next == *upright)
                {
                    printf("upright is true \n");
                }
                if (*next == *down)
                {
                    printf("down is true \n");
                }
                if (*next == *downleft)
                {
                    printf("downleft is true \n");
                    searchLetter(arr, next);
                }
                if (*next == *downright)
                {
                    printf("downright is true \n");
                    searchLetter(arr, next);
                }

                //searchLetter(arr, next);
            }
            // if(*(word + 1) == *next || *(word - 1) == *next )
            // {
            //     printf("elements next to H are %c, %c \n", *(*(arr + 1)), *(*(arr - 1)));
            // }
        }
    }
}

void searchPuzzle(char **arr, char *word)
{
    // This function checks if arr contains the search word. If the
    // word appears in arr, it will print out a message and the path
    // as shown in the sample runs. If not found, it will print a
    // different message as shown in the sample runs.
    // Your implementation here...

    //Convert lowercase letters into upper case
    for (int i = 0; *(word + i) != '\0'; i++)
    {
        if (*(word + i) >= 'a' && *(word + i) <= 'z')
        {
            *(word + i) = *(word + i) - 32;
        }
    }
    printf("word %s \n", word);

    //Search Algorithm
    searchLetter(arr, word);

    //int wordSize = strlen(word); //checks word size
    //printf("This is the first letter %c \n", *(word)); //this works
    //printf("This is arr %c \n", **arr);

    //Traversing the array to find the first letter
    // for (int i = 0; i < bSize; i++)
    // {
    //     for (int j = 0; j < bSize; j++) //accessing columns with j
    //     {
    //         if (*word == *(*(arr + i) + j))
    //         {
    //printf("Found %c at %d,%d \n", *word, i, j);
    //break;
    //printf("This is word: %c \n", *word);
    //printf("This is arr: %c \n", *(*(arr + i) + j));

    //look for next letter
    //char next = *(word + 1);
    //printf("this is next %c \n", next);
    // if(*(word + i)){
    //     //printf("Found %c at %d,%d \n", *word, i, j);
    // //break;
    // }
    //}
    // else if (*word == *(*(arr + i) + j))
    // {
    //     printf("FOUND! \n");
    //     break;
    // }
    //}
    // if (*word == **arr)
    // {
    //     printf("first letter found! \n");
    // }
    // else
    // {

    // }
    //}

    //int size = bSize;

    //loop that creates variables based on how many letters there are

    // for( int i =0; i < wordSize; i++){
    // char* ptr = NULL;
    // }
    //int count = 0;
    //int first = 0;

    /*for (int i = 0; i < size; i++) //accessing rows with i
    {
        for (int j = 0; j < size; j++) //accessing columns with j
        {
            for (int k = 0; k < wordSize; k++)
            { // checks to see if the letter matches.

                if (word[k] == (*(*(arr + i) + j)))
                {
                    count++;
                    declarePointer(k, (*(*(arr + i) + j)));
                }
                if (word[0] == (*(*(arr + i) + j)))
                {
                    first = 1;
                }
            }
        }
    }
    */
    /*
    if (first == 1 && count >= 1)
    {
        printf("Word found!");
    }
    else
    {
        printf("Word not found!");
        return;
    }
    */

    // printf("\n");
    // // printf("%x %x %x %x %x ",&ptr0, &ptr1, &ptr2, &ptr3, &ptr4 );

    // // printing path
    // printf("Printing the search path: \n");
    // printPath(word, arr, wordSize);

    // return;
}
