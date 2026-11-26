#include <stdio.h>

int main()
{
    char filePath[] = "C:/Users/itssk/OneDrive/Desktop/os/example.txt";

    FILE *file = fopen(filePath, "w");

    if (file == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }

    fprintf(file, "This is an example file content.");

    fclose(file);

    printf("File created successfully: %s\n", filePath);

    return 0;
}