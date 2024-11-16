#include <windows.h> // For gotoxy function
#include <string.h> // For String inputs and functions
#include <time.h> // For Time calculations
#include <stdio.h> // For printing statements

void gotoxy(int x,int y); // Function for managing cursor on CLI

int main()
{
    // ###SUBHAN'S AREA TO CODE###

    printf("************************************************************************************************************************************************************************\n\n");
    printf("*                                                                                                                                                                      *\n");
    
    printf("*  S S S S S    C C C C C  R R R R R   I I I   P P P P P P  T T T T T      V       V  E E E E E E E   L              O O O    C C C C C  I I I   T T T T T   Y       Y *\n");
    printf("* S            C           R        R    I     P         P      T           V     V   E               L             O     O  C             I         T         Y   Y   *\n");
    printf("*  S S S S     C           R R R R R     I     P P P P P P      T            V   V    E E E E E       L             O     O  C             I         T           Y     *\n");
    printf("*          S   C           R      R      I     P                T             VVV     E               L             O     O  C             I         T           Y     *\n");
    printf("* S S S S S     C C C C C  R       R   I I I   P                T              V      E E E E E E E   L L L L L L    O O O    C C C C C  I I I       T           Y     *\n\n");

    printf("*                                                                                                                                                                      *\n");
    printf("************************************************************************************************************************************************************************");

    // ############################

    // ###MOAZZAM'S AREA TO CODE###

    char c, Sentence[10000] = "This is just some text for now till mr moazzam decides to do his work"; // Store a sentence from a file using file management in C language

    // ############################

    // ###DANYAL'S AREA TO CODE###

    // main variable declaration
    long LettersLength = 0, LetterCount = 0;
    float Accuracy = 0 , Speed = 0;
    double StartTime , StopTime = 0, LetterToWord = 1;

    // Basic print statements that will be manipulated further in the code
    printf("\n\nYOUR TEXT:    \n");
    puts(Sentence);
    printf( "\n                    SPEED: 0          ACCURACY: 0        TOTAL ERROR: 0" );

    // Length of the string variable "Sentence"
    LettersLength = strlen(Sentence);

    // for-loop to calculate the number of spaces in the string "Sentence"
    for (int i = 0; i < LettersLength; i++)
        if (Sentence[i] == ' ')
            LetterToWord++;
    
    // calculate average space per character rate
    LetterToWord /= LettersLength;

    // printf("\n%ld", LetterToWord);


    printf("\n-----------------------------------------------");
    printf("\n\nEnter Any Key To Start Typing.........");

    // waits for user to press any key
    c = getch();
    
    // change the cursor point to make "Accuracy : 100%" and going back to normal cursor position 
    gotoxy(48, 9);
    printf("100%c", '%');
    gotoxy(0, 12);
    printf("ENTER THE ABOVE TEXT:                     \n\n");
    
    // Time variables using the time.h headerfile 
    time_t t,t1;

    t = clock();
    gotoxy(0,5);

    // while-loop to traverse through the string variable "Sentence"
    int k = 0, Errors = 0;
    while(Sentence[k] != NULL)
    {
        t1 = clock();
        
        c = getch();

        if(c != Sentence[k])
        {
            printf("\a");
            Errors++;
            
            Accuracy = ((float)100/LettersLength)*(LettersLength-Errors);
            
                if(Accuracy <= 0)
                {
                    gotoxy(48, 7);
                    printf("0.00%c    ",'%');
                }
                if(Accuracy > 0)
                {
                    gotoxy(48, 7);
                    printf("%0.2f%c ", Accuracy, '%');
                }

            gotoxy(70, 7);
            printf("%d", Errors);
            gotoxy(0, 5);

            for(int j = 0; j < k; j++)
                printf("%c", Sentence[j]);
        }
        else
        {
            LetterCount++;
            gotoxy(0,12);

            for(int j = 0; j < k; j++)
                printf("%c", Sentence[j]);
            printf("%c", c);
            k++;
        }

            t1 = clock() - t1;
            StartTime=((double)t1/CLOCKS_PER_SEC);
            StopTime = StopTime + StartTime;
            
            gotoxy(27,7);
            printf("%0.2f WPM ", (float)(LetterToWord*LetterCount)/(StopTime/60));
            
            gotoxy(0,5);
            for(int j=0; j<k; j++)
                printf("%c", Sentence[j]);
    }

    t=clock()-t;

    double YourTime =((double)t/CLOCKS_PER_SEC);
    YourTime -= (YourTime-StopTime);

    gotoxy(0,5);

    for(int j = 0; j < k; j++)
        printf("%c",Sentence[j]);

    return 0;


}   

void gotoxy(int x,int y){

    COORD coord;

    coord.X = x ;
    coord.Y = y ;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
