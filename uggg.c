#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> // used to access and read the contents of directories

void createFile(char filename[100], char extension[20]) {
    FILE *p;
    char fullFilename[120];
    sprintf(fullFilename, "%s.%s", filename, extension);
    p = fopen(fullFilename, "w");
    if (p == NULL) {
        printf("The file couldn't be created!");
    } else {
        printf("File created successfully!!");
    }
    fclose(p);
}

void newfile() {
    char filename[120], extension[20], actualFilename[100];
    int c, i;
    while ((c = getchar()) != '\n' && c != EOF); // flush stdin

UserInputFileName:
    printf("\nEnter file name (with extension .txt or .bin): ");
    if (fgets(filename, sizeof(filename), stdin)) {
        filename[strcspn(filename, "\n")] = '\0';  // Remove newline

        char *dot = strrchr(filename, '.');
        if (dot && dot != filename && *(dot + 1) != '\0') {
            size_t nameLength = dot - filename;
            strncpy(actualFilename, filename, nameLength);
            actualFilename[nameLength] = '\0';
            strcpy(extension, dot + 1);
        } else {
            printf("Invalid filename or missing extension.\n");
            goto UserInputFileName;
        }

        for (i = 0; filename[i] != '\0'; i++) {
            if (filename[i] == '\\' || filename[i] == '/' || filename[i] == '?' ||
                filename[i] == '*' || filename[i] == ':' || filename[i] == '"' ||
                filename[i] == '<' || filename[i] == '>' || filename[i] == '|') {
                printf("\nPlease enter again!");
                goto UserInputFileName;
            }
        }

        if (strcmp(extension, "txt") != 0 && strcmp(extension, "bin") != 0) {
            printf("\n Please use either .txt or .bin as extension");
            goto UserInputFileName;
        }

        createFile(actualFilename, extension);
    }
}	
  void loadfile() {
    int count = 0;
    struct dirent *entry;
    DIR *folder = opendir(".");

    if (folder == NULL)
	 {
        printf("Could not open folder.\n");
    } 
	else
	 {
        printf("\n The current directory notepad files :\n");

        while ((entry = readdir(folder)) != NULL) 
		{
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            char *ext = strrchr(entry->d_name, '.');
            if (ext != NULL && (strcmp(ext, ".txt") == 0 || strcmp(ext, ".bin") == 0))
			 {
                printf(" - %s\n", entry->d_name);
                count++;
            }
        }

        if (count == 0) 
		{
            printf("No .txt or .bin files found.\n");
        }

        closedir(folder);
    }
}      

int main() {
    int ch;
    printf("\t\t\t\t**Welcome to mini notepad!**\t\t\t\t");
    printf("\n1. Create a New File");
    printf("\n2. Open Existing File");
    printf("\n3. Save Current File");
    printf("\n4. Load Existing Files");
    printf("\n5. Exit Editor");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            newfile();
            break;

        case 2:
            break;

        case 3:
           break;

        case 4: 
             loadfile();
             break;
		 

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

