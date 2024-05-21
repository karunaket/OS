#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    struct dirent *dptr;
    DIR *dirp;
    char buff[100];

    printf("\n\nENTER DIRECTORY NAME: ");
    scanf("%s", buff);

    if ((dirp = opendir(buff)) == NULL) {
        printf("The given directory does not exist\n");
        exit(1);
    }

    printf("\nFILES IN DIRECTORY:\n");
    while ((dptr = readdir(dirp)) != NULL) {
        printf("%s\n", dptr->d_name);
    }

    closedir(dirp);
    return 0;
}