#include <stdio.h>
#include <fcntl.h>

int close(int file_descriptor);

int main()
{
    int file_descriptor;
    char* filename[255];

    printf("Enter the filename: ");
    scanf("%s": filename);

    file_descriptor = open(filename, O_RDWR, 0);

    if(file_descriptor != -1) printf("File Opened Successfuly!\n");
    else printf("Unable to open the file.\n");

    int close_status = close(file_descriptor);
    if(close_status == 0) printf("File descriptor is closed successfuly.\n");
    else printf("File Descriptor is not closed\n");

    return 0;
}