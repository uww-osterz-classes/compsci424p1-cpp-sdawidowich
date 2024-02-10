#include "version1.h"

Version1::Version1() { 
      /* Default constructor. Use this to allocate (if needed) and
      initialize the PCB array, create the PCB for process 0, and do
      any other initialization that is needed. 
      */ 
}

Version1::~Version1() {
    /* Destructor. If you allocated anything with "new" during
    the lifetime of this object, and you haven't yet "delete"d
    it, "delete" it (using the "delete" keyword) here.
    */
}

/* Creates a new child process of process with ID parentPid. 
*/
int Version1::create(int parentPid) {
    // If parentPid is not in the process hierarchy, do nothing; 
    // your code may return an error code or message in this case,
    // but it should not halt.

    // Assuming you've found the PCB for parentPid in the PCB array:
    // 1. Allocate and initialize a free PCB object from the array
    //    of PCB objects

    // 2. Insert the newly allocated PCB object into parentPid's
    //    list of children

    // You can decide what the return value(s), if any, should be.
    return 0; // often means "success" or "terminated normally"
}

/* Recursively destroys the process with ID parentPid and all of
its descendant processes (child, grandchild, etc.).
*/
int Version1::destroy(int targetPid) {
    // If targetPid is not in the process hierarchy, do nothing; 
    // your code may return an error code or message in this case,
    // but it should not halt

    // Assuming you've found the PCB for targetPid in the PCB array:
    // 1. Recursively destroy all descendants of targetPid, if it
    //    has any, and mark their PCBs as "free" in the PCB array 
    //    (i.e., deallocate them)

    // 2. Remove targetPid from its parent's list of children

    // 3. Deallocate targetPid's PCB and mark its PCB array entry
    //    as "free"

    // You can decide what the return value(s), if any, should be.
    return 0; // often means "success" or "terminated normally"
}

/* Traverse the process creation hierarchy graph, printing
information about each process as you go. See Canvas for the
*required* output format. 

You can directly use "cout" or "printf" statements to send
the required output to stdout, or you can change the return
type of this function to return the text to the main program
for printing. It's your choice. 
*/
void Version1::showProcessInfo() {
    for (int i = 0; i < this->pcbArray.size(); i++) {
        Version1PCB p = this->pcbArray[i];
        std::cout << "Process " << i << ": parent is " << p.getParent() << " and ";
        if ((p.getChildren().size() > 0)) {
            std::cout << "children are";
            for(auto child = p.getChildren().begin(); child != p.getChildren().end(); child++) {
                std::cout << ' ' << *child;
            }
        }
        else {
            std::cout << "has no children";
        }
        std::cout << std::endl;
    }
}