/*                                                                               *\
                                Excersize 1-17
                              Print Longest Line
\*                                                                               */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ReturnLongest(int *StrIndex, int IndexSize);
void PrintLongest(char *StringArray, int StringSize , int MaxLength);

int main(){
    char *FullString = calloc(0,sizeof(char));
    int *StrLoc = calloc(0,sizeof(int));
    int LastDigit;
    int Lines = 0, CharCounter = 0;
    for (int CurrentChar, i= 0; (CurrentChar = getchar())!= EOF; i++)
    {
        FullString = realloc(FullString,sizeof(char)*i + 1);
        FullString[i] = CurrentChar;
        LastDigit = i + 1;
    }  
    
    for(int i = 0; i < LastDigit; i++)
    {   
        CharCounter++;
        if (FullString[i] == '\n')
        {
            Lines++;
            StrLoc = realloc(StrLoc,sizeof(int)* Lines);
            StrLoc[Lines - 1] = CharCounter - 1;
            CharCounter = 0;
        }
    }
    PrintLongest(FullString, LastDigit, ReturnLongest(StrLoc, Lines));
    free(FullString);
    free(StrLoc);
    return 0;
}


int ReturnLongest(int *StrIndex, int IndexSize)
{
    int Greatest = 0;
    for (int i = 0; i< IndexSize; i++)
        if (StrIndex[i]>Greatest)
            Greatest = StrIndex[i];
    return Greatest;
}

void PrintLongest(char *StringArray, int StringSize , int MaxLength)
{
    for (int i = 0, Tracker = 0; i < StringSize;i++)
    {
        Tracker++;
        if (StringArray[i] == '\n')
        {
            if (Tracker - 1 == MaxLength)
            {
                for (int PrintC = i - Tracker; PrintC < i; PrintC++)
                    printf("%c",StringArray[PrintC + 1]);
            }
            Tracker = 0;
        }
    }
}
