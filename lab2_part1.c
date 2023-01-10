/*+
 * Module:  lab2.c
 *
 * Purpose: Skeleton solution to ELEC 377 Lab2.
 *
-*/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>

static struct task_struct * firstTask, *theTask;
//TEST
int cnt;

int my_read_proc(char * page, char **start, off_t fpos, int blen, int * eof, void * data){

    int numChars;
    if (fpos == 0){
        numChars = sprintf(page, "Hello");
        //add numChars to page so that the second write starts from where the first write left off. Sincesprintf returns the number of characters written by this call, you have to add the return value to numChars.
        numChars += sprintf(page + numChars, " World\n");
        
        // write headers
	    // find first task
        // write first task
        // advance to next task
    } else {
        //if (at back at begining of list){
            *eof = 0;
            *start = page;
            return 0;
        //}
	    // write task info for one task
	    // advance to next task
    }
    *eof = 1;
    *start = page;
    return numChars;
}

int init_module(){
   struct proc_dir_entry * proc_entry;
    //Fix this part:
    proc_entry = create_proc_entry("lab2", 0444, NULL);
    if (proc_entry !=NULL){
        proc_entry->read_proc = my_read_proc;
    } else {
        return -1;
    }
}

void cleanup_module(){
    remove_proc_entry("lab2", NULL);
}
