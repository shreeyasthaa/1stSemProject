//basic structure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void createFile(char filename[100], char extension[20]){
    FILE *p;
    char fullFilename[120];
    sprintf(fullFilename, "%s.%s", filename, extension);
    p=fopen(fullFilename,"w");
    if(p==NULL){
    	printf("The file couldnt be created!");
	}
	else{
		printf("File created successfully!!");
	}
	fclose(p);
}
void newfile(){
	char filename[120],extension[20], actualFilename[100];
	int c,i;
    while ((c = getchar()) != '\n' && c != EOF);//getchar na halda lekhna diyena \n janthiyo fgets ma
    UserInputFileName:
    InvalidInput:
	printf("\nEnter file name(with extension .txt or .bin): ");
    if (fgets(filename, sizeof(filename), stdin)) {
       filename[strcspn(filename, "\n")] = '\0';  // Remove newline
        // Find last dot
        char *dot = strrchr(filename, '.');
        if (dot && dot != filename && *(dot + 1) != '\0') {//dot bhaneko .txt
            size_t nameLength= dot-filename;
            strncpy(actualFilename, filename, nameLength);
            actualFilename[nameLength] = '\0';  // Null-terminate
            strcpy(extension, dot+1);  // Copy extension
        } 
        else {
            printf("Invalid filename or missing extension.\n");
            goto UserInputFileName;
        }
        for(i=0; filename[i] != '\0'; i++) {
	        if(filename[i] == '\\' || filename[i] == '/' || filename[i] == '?' || 
	           filename[i] == '*'  || filename[i] == ':' || filename[i] == '"' || 
	           filename[i] == '<'  || filename[i] == '>' || filename[i] == '|'){
		        printf("\nPlease enter again!");
	            goto UserInputFileName;
		    }
		}
		if (strcmp(extension,"txt") != 0 && strcmp(extension,"bin") != 0) {
		    printf("\nPlease use either .txt or .bin as extension");
		    goto UserInputFileName;
		}
	      createFile(actualFilename, extension);
    }
}

	
int main(){
	int ch;
	printf("\t\t\t\t**Welcome to mini notepad!**\t\t\t\t");
	printf("\n1.Create a New File");
	printf("\n2.Open Existing File");
	printf("\n3.Save Current File");
	printf("\n4.Load existing files");
	printf("\n5.Exit editor");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			newfile();
		break;
		case 2:
			
		break;
		case 3:
		
		break;
		case 4:
		
		break;
		
			
	}
	return 0;
}
