#include "../headers/version1.h"

Version1::Version1() { 
      /* Default constructor. Use this to allocate (if needed) and
      initialize the PCB array, create the PCB for process 0, and do
      any other initialization that is needed. 
      */
     
    this->pcbArray.push_back(new Version1PCB());
}

Version1::~Version1() {
    /* Destructor. If you allocated anything with "new" during
    the lifetime of this object, and you haven't yet "delete"d
    it, "delete" it (using the "delete" keyword) here.
    */
    this->deletePCBs();
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
    if (parentPid > this->pcbArray.size() - 1 || parentPid < 0 || this->pcbArray[parentPid] == nullptr) {
        return 1;
    }
    
    int pid = this->pcbArray.size();

    this->pcbArray.push_back(new Version1PCB(parentPid));
    this->pcbArray[parentPid]->addChild(pid);

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

    if (targetPid > this->pcbArray.size() - 1 || targetPid < 0 || this->pcbArray[targetPid] == nullptr) {
        return 1;
    }

    auto children = this->pcbArray[targetPid]->getChildren();
    for (auto& child : children) {
        this->destroy(child);
    }
    
    int parent = this->pcbArray[targetPid]->getParent();
    this->pcbArray[parent]->removeChild(targetPid);

    delete this->pcbArray[targetPid];
    this->pcbArray[targetPid] = nullptr;

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
        if (this->pcbArray[i] == nullptr) {
            continue;
        }

        Version1PCB* p = this->pcbArray[i];
        std::list<int> pChildren = p->getChildren();

        std::cout << "Process " << i << ": parent is " << p->getParent() << " and ";
        if ((pChildren.size() > 0)) {
            std::cout << "children are";
            for(auto& child : pChildren) {
                std::cout << ' ' << child;
            }
        }
        else {
            std::cout << "has no children";
        }
        std::cout << std::endl;
    }
}

void Version1::deletePCBs() {
    for (auto& p : this->pcbArray) {
        delete p;
    }
}

void Version1::resetPCBArray() {
    this->deletePCBs();
    this->pcbArray.clear();
    this->pcbArray.push_back(new Version1PCB());
}