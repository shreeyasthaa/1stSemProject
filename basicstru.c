//basic structure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void createFile(char filename[100], char extension[20]){
    FILE *p;
    char fullFilename[120];
    sprintf(fullFilename, "%s.%s", filename, extension);
    p=fopen(fullFilename,"a");
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
//void editfile(){
//	int n;
//	FILE *p;
//	printf("\nEnter which file you want to edit: ");
//	 if (fgets(n, sizeof(n), stdin)){
//        
//	 }
//
//}
void deletefile(){
	char filename[120];
    printf("\nEnter the file you want to delete: ");
	if (scanf("%s", filename) != 1) {   /* guard against bad input ani filename array bhayera & chaidaina*/
	    printf("Invalid input");
	    exit(0);
	}
	if (remove(filename) == 0) {
	    puts("File deleted successfully.");
	} 
	else {
	    printf("Error deleting file!!");     /* prints the OS error */
	}    
}
	
int main(){
	int ch;
	char choice;
	printf("\t\t\t\t**Welcome to mini notepad!**\t\t\t\t");
	initial:
	printf("\n===========================\n");
	printf("***Menu***");
	printf("\n1.Create a New File");
	printf("\n2.Open Existing File");//
	printf("\n3.Load all existing files");
	printf("\n4.Edit a File");
	printf("\n5.Delete a file");
	printf("\n6.Exit editor");
	printf("\n===========================\n");
	printf("Enter your choice: ");
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
		 // editfile();
		break;
		case 5: {  
		   loadfile();                       
    	   deletefile();  
		break;  
		}                    	
		case 6:
			end:
			printf("\nExiting notepad...");
			printf("\nExited successfully!");
			exit(0);
		default:
			printf("Error!");
	}
	printf("\nDo you want to continue?Y/N ");
	scanf(" %c",&choice);
	if(choice=='Y'||choice=='y'){
		goto initial;
	}
	else{
		printf("Bye bye!");
		goto end;
	}
	
	return 0;
}
