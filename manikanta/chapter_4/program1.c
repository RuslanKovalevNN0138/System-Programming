#include <stdio.h>
#include <fcntl.h>

int main()
{
    int file_descriptor;
    char filename[255];

    printf("Enter the filename: ");
    scanf("%s",filename);
    file_descriptor = open(filename, O_RDONLY);

    /*
    On success: It returns any value other than -1.
    */

    if(file_descriptor != -1){
        printf("%s Opened Successfully!",filename);
    } else 
        printf("Unable to open %s", filename);
    return 0;
}