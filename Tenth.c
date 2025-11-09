#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourceName[100], destName[100];
    char ch;
    printf("Enter source file name (e.g., input.txt): ");
    scanf("%s", sourceName);
    printf("Enter destination file name (e.g., output.txt): ");
    scanf("%s", destName);
    sourceFile = fopen(sourceName, "r");
    if (sourceFile == NULL) {
        printf("Error: Cannot open source file %s\n", sourceName);
        exit(1);
    }
    destFile = fopen(destName, "w");
    if (destFile == NULL) {
        printf("Error: Cannot create destination file %s\n", destName);
        fclose(sourceFile);
        exit(1);
    }
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }
    printf("File copied successfully from %s to %s\n", sourceName, destName);
    fclose(sourceFile);
    fclose(destFile);
    return 0;
}
