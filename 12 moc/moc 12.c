#include <stdio.h>
#include <stdlib.h>

void encryptDecryptFile(const char *inputFile, const char *outputFile, char key) {
    FILE *fin = fopen(inputFile, "rb");
    FILE *fout = fopen(outputFile, "wb");

    if (fin == NULL || fout == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    int byte;
    while ((byte = fgetc(fin)) != EOF) {
        fputc(byte ^ key, fout);
    }

    fclose(fin);
    fclose(fout);
}

int main() {
    char inputFile[256], outputFile[256];
    char key;

    printf("Enter the input file name: ");
    scanf("%255s", inputFile);

    printf("Enter the output file name: ");
    scanf("%255s", outputFile);

    printf("Enter the encryption key (character): ");
    scanf(" %c", &key);

    encryptDecryptFile(inputFile, outputFile, key);

    printf("Process completed. Output saved to %s.\n", outputFile);

    return 0;
}
