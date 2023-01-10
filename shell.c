//+
// File:    shell.c
//
// Purpose:    This program implements a simple shell program. It does not start
//        processes at this point in time. However, it will change directory
//        and list the contents of the current directory.
//
//        The commands are:
//           cd name -> change to directory name, print an error if the directory doesn't exist.
//                      If there is no parameter, then change to the home directory.
//           ls -> list the entries in the current directory.
//                  If no arguments, then ignores entries starting with .
//                  If -a then all entries
//           pwd -> print the current directory.
//           exit -> exit the shell (default exit value 0)
//
//        if the command is not recognized an error is printed.
//-

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <ctype.h>

#define CMD_BUFFSIZE 1024
#define MAXARGS 10

int splitCommandLine(char * commandBuffer, char* args[], int maxargs);
void doCommand(char * args[], int nargs);

int main() {

    char commandBuffer[CMD_BUFFSIZE];
    char *args[MAXARGS];
    int argc;
    
    splitCommand();
    // print prompt.. fflush is needed because
    // stdout is line buffered, and won't
    // write to terminal until newline
    printf("%%> ");
    fflush(stdout);

    while(fgets(commandBuffer,CMD_BUFFSIZE,stdin) != NULL){

    // Remove newline at end of buffer
    // TODO Step 2: remove newline from end of buffer
    
    commandBuffer[strlen(commandBuffer) - 1] = '\0';
    
    /*OR char *ptr = strchr(buf, '\n');
        if (ptr)
        {
            //if new line found replace with null character
            *ptr  = '\0';
        }*/
        
    // Split command line into words.
    // TODO Step 2: call splitCommandLine with the right parameters
    
    int splitCommandLine(char * commandBuffer, char* args[], int maxargs){
        //uses arguments commandbuffer, args array, length array
        //finds the words and stores pointers to the beginning of each word, then returns the num of words
        
        char *p = commandbuffer;
        int numwords = 0;

        while(1) //isspace finds white character, built in func
            {
            while(isspace(*p)) //while loops finds space
                p++;

            if(*p == '\0') //when not a space, beginning of word and stored in array and places pointer in arr
                return numwords;
            args[numwords++] = p; //each time word found, increments

            while(!isspace(*p) && *p != '\0') //if finds '\0', indication of the end
                p++;

            if(*p == '\0')
                return numwords;
            *p++ = '\0';

            if(numwords >= maxargs)
                return numwords;
            }

        }
        
    // Debugging for step 2
    //printf("%d\n", nargs);
    //int i;
    //for (i = 0; i < nargs; i++){
    //  printf("%d: %s\n",i,args[i]);
    //}

    // Execute the command
    // Remember to check if there is a command (i.e. value of nargs)
    // TODO: Step 3 call doCommand with the right arguments

    // print prompt
    printf("%%> ");
    fflush(stdout);
    }
}

////////////////////////////// String Handling ///////////////////////////////////

//+
// Function:    skipChar
//
// Purpose:    This function skips over a given char in a string
//        For security, the function will not skip null chars.
//
// Parameters:
//    charPtr    Pointer to string
//    skip    character to skip
//
// Returns:    Pointer to first character after skipped chars.
//        Identity function if the string doesn't start with skip,
//        or skip is the null character
//-

char * skipChar(char * charPtr, char skip){
 // TODO Step 2: skip over instances of the char skip
 // return input value of charPtr if *char is null char
    
    //So when passed a pointer to the beginning of the array
    //commandBuffer, and the space character (' '), it will return a pointer to the first 't' character in the array.
    
    
    //If the character to be skipped is a null character,
    //it returns the pointer it was given (i.e. the first parameter) unchanged.
    if skip == NULL{
        return charPtr;
    }
}

//+
// Function:    splitCommandLine
//
// Purpose:    This splits a string into an array of strings.
//        The array is passed as an argument. The string
//        is modified by replacing some of the space characters
//        with null characters to terminate each of the strings.
//
// Parameters:
//    commandBuffer    The string to split
//    args        An array of char pointers
//    maxargs        Size of array args (max number of arguments)
//
// Returns:    Number of arguments (< maxargs).
//
//-

int splitCommand(char * commandBuffer, char* args[], int maxargs){
   // TODO Step 2 split the command into words using only
   // the functions skipChar and strchr. You may use fprintf to report
   // errors that are encountered to stderr.
    // The only functions splitCommand may call are skipChar, and the library function strchr and fprintf (to report an error: what is the one error?).
    
    
    // The function fprintf takes a file as the first parameter. That file should be the predefined file stderr, which is the standard error stream to the terminal.
    
    
    // You add a call to splitCommand in the main function.
    
    
    // You will have to declare a local variable in main to store the number of arguments returned by the function splitCommand.
    return argc;
}


////////////////////////////// Command Handling ///////////////////////////////////

// typedef for pointer to command handling functions

// TODO STEP 3a write the typedef for the function handler pointer to
// use in the structure immediately below.
// See the description of the function prototypes at the bottom of
// the file in the comments.
// cmdStruct type:
// Associates a command name with a command handling function

typedef void (*commandPointer)( char *args[], int nArgs);

// TODO STEP 3b use the typedef above (Step 3a) to make a two element
// struct. The first is a char * for the name of the command
// the other is a function pointer for the command handling function
// typedef struct {
//
// } typename;

typedef struct {
    char *cmdName;
    functionPointer fxnp;

} commandType;

// prototypes for command handling functions
// TODO STEP 4b,6: add a function prototype
// for each command handling function

// Array that provides the list commands and functions
// must be terminated by {NULL, NULL}
// in a real shell, this would be a hashtable.

// TODO Step 4a: add a global array of
// the type above that contains initializers
// of strings and command handling function names
structType commandarrayname[] = {
    {"exit", exitFunc, NULL, NULL }
};

//+
// Function:    doCommand
//
// Purpose:    This command calls a command handling funciton from
//        the commands array based on the first argument passed
//        in the args array.
//
// Parameters:
//    args    command and parameters, an array of pointers to strings
//    nargs    number of entries in the args array
//
// Returns    nothing (void)
//-

void doCommand(char * args[], int nargs){
   // TODO Step 5 this function is small
   //  this is the command search loop
    
    //Add a call to doCommand function in the main program to execute commands after they have been split into words.
    
    //simple loop that compares the first field of each element of the array to args[0].
    do{
        //If true, then it calls the associated command function and returns from doCommand.
       
        if(args[0] = NULL){
            return;
        }
        
        if(){ //reaches the end of the array without a match
            fprintf(stderr, "error, command not recognized");
        }
    }
    while(strcmp(args[], args[0])>0); //compares first field of each element to args[0], true if >0
}

//////////////////////////////////////////////////
//            command Handling Functions        //
//////////////////////////////////////////////////
// all command handling functions have the same
// parameter types and return values.
//////////////////////////////////////////////////

//+
// Function:    all handling functions
//
// Purpose:    this command performs the function
//        associated with the commands.
//        The name of the comomand is in first argument.
//         Since it is called by doCommand, it is known
//        that arg is at least one element long
//
// Parameters:
//    args    command and parameters, an array of pointers to strings
//    nargs    number of entries in the args array
//
// Returns    nothing (void)
//-


// TODO step 4b put command handling function for exit here
// e.g. void exitFunc(char * args[], int nargs){
// }

void exitFunc(char * args[], int nargs){
    exit(0);
}

// TODO step 6 put rest of command handling functions here

void cdFunc(char *args[], int nargs) {
    char * cwd = getcwd(NULL,0);
    char *chdir;
    if (nargs == 1) {
        // Change to home directory
        struct passwd *pw = getpwuid(getuid());
        if(*pw !=NULL){
            if((*pw).pw_dir != NULL){
            }else{
                fprintf(stderr, "error, pw dir is null"\n");
            }
            }else{
                fprintf(stderr, "error, dir not able to open"\n);
            }
    }else if (nargs ==2){
    chdir(args[1]);
    }
}
                        
//Rest of step 6
                        
struct dirent ** namelist;
int numEnts = scandir(".",&namelist,NULL,NULL);

namelist[0]->d_name
int filter(const struct dirent * d);
                        
}
