#include <windows.h> // For gotoxy function
#include <string.h> // For String inputs and functions
#include <time.h> // For Time calculations
#include <stdio.h> // For printing statements
#include <stdlib.h>

void gotoxy(int x,int y); // Function for managing cursor on CLI

int main()
{
    system("cls");
    // ###SUBHAN'S AREA TO CODE###

    printf("\n\n");
    printf("  _________            .__        __ ____   ____     .__                .__  __          \n");
    printf(" /   _____/ ___________|__|______/  |\\   \\ /   /____ |  |   ____   ____ |__|/  |_ ___.__.\n");
    printf(" \\_____  \\_/ ___\\_  __ \\  \\____ \\   __\\   Y   // __ \\|  |  /  _ \\_/ ___\\|  \\   __<   |  |\n");
    printf(" /        \\  \\___|  | \\/  |  |_> >  |  \\     /\\  ___/|  |_(  <_> )  \\___|  ||  |  \\___  |\n");
    printf("/_______  /\\___  >__|  |__|   __/|__|   \\___/  \\___  >____/\\____/ \\___  >__||__|  / ____|\n");
    printf("        \\/     \\/         |__|                     \\/                 \\/          \\/     \n");
    printf("\n\n");
   
    // ############################

    // ###MOAZZAM'S AREA TO CODE###
    FILE *file;
    int total_sentences = 10;
    int random_line;
    srand(time(NULL));

    random_line = rand() % total_sentences;

    file = fopen("sentences.txt", "r");

    char c, Sentence[10000]; // Store a sentence from a file using file management in C language

    for (int i = 0; i <= random_line; i++) {
        if (fgets(Sentence, sizeof(Sentence), file) == NULL) {
            printf("Error: Could not read the file.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    size_t len = strlen(Sentence);
    if (Sentence[len - 1] == '\n') {
        Sentence[len - 1] = '\0';
    }
    
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
    gotoxy(48, 15);
    printf("100%c", '%');
    gotoxy(0, 18);
    printf("ENTER THE ABOVE TEXT:                     \n\n");
    
    // Time variables using the time.h headerfile 
    time_t t,t1;

    t = clock();
    gotoxy(0,13);

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
                    gotoxy(48, 15);
                    printf("0.00%c    ",'%');
                }
                if(Accuracy > 0)
                {
                    gotoxy(48, 15);
                    printf("%0.2f%c ", Accuracy, '%');
                }

            gotoxy(70, 15);
            printf("%d", Errors);
            gotoxy(0, 13);

            for(int j = 0; j < k; j++)
                printf("%c", Sentence[j]);
        }
        else
        {
            LetterCount++;
            gotoxy(0,20);

            for(int j = 0; j < k; j++)
                printf("%c", Sentence[j]);
            printf("%c", c);
            k++;
        }

            t1 = clock() - t1;
            StartTime=((double)t1/CLOCKS_PER_SEC);
            StopTime = StopTime + StartTime;
            
            gotoxy(27,15);
            printf("%0.2f WPM ", (float)(LetterToWord*LetterCount)/(StopTime/60));
            
            gotoxy(0,13);
            for(int j=0; j<k; j++)
                printf("%c", Sentence[j]);
    }

    t=clock()-t;

    double YourTime =((double)t/CLOCKS_PER_SEC);
    YourTime -= (YourTime-StopTime);

    gotoxy(0,20);

    for(int j = 0; j < k; j++)
        printf("%c",Sentence[j]);

    
    printf("\n\n-----------------------------------------------\n\n");
    printf("YOUR RESULT");
    printf("\n\nYOUR SPEED: %0.2f WPM  \n\n** ( Length Of One Word Is Taken As %0.2f Letters )\n", (LetterToWord*LettersLength)/(YourTime/60),(float)LettersLength/(LetterToWord*LettersLength));
    printf("\nEnter Any Key to Exit......");
    getch();
    return 0;


}   

void gotoxy(int x,int y)
{

    COORD coord;

    coord.X = x ;
    coord.Y = y ;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
