// Lab 2 - ELEC 377
// Jake, Dylan
// Extension was granted, check GitLab .jpeg

//START
#include <linux/kernel.h> //Include libraries
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>

static struct task_struct * firstTask, *theTask;

int cnt;

/*-------------------------------------------------------------------------------------------------------------------------------*/
// my_read_proc
/*-------------------------------------------------------------------------------------------------------------------------------*/

int my_read_proc(char * page, char **start, off_t fpos, int blen, int * eof,void * data){

    int numChars = 0;   //initializations
    int numPage = (PAGE_SIZE >> 10);    //numPage contains value of size of page

/*-------------------------------------------------------------------------------------------------------------------------------*/
//  if statement - if the current task is the same as the first task, set variables and 
//  return

/*-------------------------------------------------------------------------------------------------------------------------------*/
//  else if - if position is zero, start
/*-------------------------------------------------------------------------------------------------------------------------------*/
    
    
    if (fpos == 0){    //find first valid task
        theTask = (&init_task); //assign address of the variable init_task to the variable theTask
    
        // SPACING FOR HEADING
        numChars = sprintf(page, "\n\tPID\tUID\tVSZ\tRSS\n"); 

        while ((theTask->pid) == 0) {   //while loop to identify firstTask with PID value !=0
            theTask = (theTask->next_task);   //copies pointer to theTask 
        }
        firstTask = theTask;

        //Below adds process id + user id to page buffer
        numChars += sprintf(page + numChars, "\t%4d\t%4d\n", (firstTask->pid, firstTask->uid)); 
        
        if ((firstTask->mm) == NULL) {       
            numChars += sprintf(page + numChars, "%4d \t%4d\n", 0,0);
        }
        else {  //if not true                             
            numChars += sprintf(page + numChars, "\t%4d \t%4d\n", firstTask->mm->total_vm * numPage, firstTask->mm->rss * numPage);
        }

        do {    //do while loop to move theTask to point to next valid task
            theTask = (theTask->next_task);
        } while ((theTask->pid) == 0);  //while not 0
    } 
    else {
        if (theTask == firstTask){ 
            *start = page;
            *eof = 0;
            return 0;
        }

        //Below adds process id + user id to page buffer
        numChars = sprintf(page, "\t%4d\t%4d", (theTask->pid), (theTask->uid));
        if ((theTask->mm) == NULL) {
        numChars += sprintf(page + numChars, "%4d \t%4d\n", 0,0);
        } 
        else {    //if not true    
        numChars += sprintf(page + numChars, "\t%4d \t%4d\n", theTask->mm->total_vm * numPage, theTask->mm->rss * numPage);
        }

        do {    //do while loop to move theTask to point to next valid task
            theTask = (theTask->next_task);
        } while ((theTask->pid) == 0);  //while not 0
    }
    *start = page;  //pointer to start of page
    *eof = 1;   //sets end of page to 1
    return numChars; //returns numChars after if statements
}
/*-------------------------------------------------------------------------------------------------------------------------------*/
//  else - no conditions are met, prints error to cmd
/*-------------------------------------------------------------------------------------------------------------------------------*/
// init_module
/*-------------------------------------------------------------------------------------------------------------------------------*/

int init_module(){
    //create proc_entry
    struct proc_dir_entry * proc_entry;
    proc_entry = create_proc_entry("lab2", 0444, NULL);

    //determine if creation was successful or not
    if (proc_entry == NULL) {   //create failed
        return -1;
    }
    else {  //did not fail
        proc_entry->read_proc = my_read_proc;
        return 0;
    }
}
/*-------------------------------------------------------------------------------------------------------------------------------*/
// cleanup_module
/*-------------------------------------------------------------------------------------------------------------------------------*/
void cleanup_module()
{
    remove_proc_entry("lab2", NULL);
}
//END
