#include "Header.h"

const char input[] = "Input.txt";

int LenghtOfFile()
{
    struct stat buff;
    stat(input, &buff);
    unsigned long len_onegin = buff.st_size;

    return len_onegin;
}
void InputText(char* Text, int lenght)
{
    FILE* potok = NULL;

    if ((potok = fopen(input, "r+")) == NULL) {
        printf("Failed to open input file. LINE: %d\n", __LINE__);
        free(Text);
        //return -1;
    }

    fread(Text, sizeof(char), lenght, potok);

    fclose(potok);
}
int SumString(char* onegin)
{
    int sum_string = 0;
    int i = 0;

    for (i; onegin[i] != '\0'; i++)
    {
        if (onegin[i] == '\n')
        {
            sum_string++;
        }
    }

    return sum_string;
}
void FillStruct(struct LineInfo* Line, char* Text, int lenght, int sum_string)
{
    int i = 0;
    int j = 1;

    Line[0].index = Text;

    for (i; i < lenght; i++)
    {
        if (Text[i] == '\n')
        {
            Text[i] = '\0';
            Line[j].index = &Text[i + 1];

            j++;
        }
    }

    for (i = 0; i <= sum_string; i++)
    {
        for (j = 0; *(Line[i].index + j) != '\0'; j++) {}
        Line[i].len = j - 1;
    }
}
