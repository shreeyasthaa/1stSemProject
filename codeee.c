#include <stdio.h>
#include <string.h>

void save(const char *filename, const char *content) {
    FILE *file = fopen(filename, "a");  
    if (file == NULL) {
        printf("Error: Could not open file '%s' for saving.\n", filename);
        return;
    }

    fputs(content, file);  
    fclose(file);
    printf("[Auto-saved to %s]\n", filename);
}

int main() {
    char filename[100];
    char content[10000] = "";  
    printf("Enter the filename to edit/save: ");
    scanf("%s", filename);  
    getchar(); 

    printf("\nType something to add (type 'exit' to quit):\n");

    while (1) {
        char line[256];
        printf("> ");
        fgets(line, sizeof(line), stdin);

        if (strncmp(line, "exit", 4) == 0)
            break;

       
        strncat(content, line, sizeof(content) - strlen(content) - 1);

        
        save(filename, content);
    }

    return 0;
}
