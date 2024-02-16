#include "../headers/version2.h"

Version2::Version2() { 
    /* Default constructor. Use this to allocate (if needed) and
    initialize the PCB array, create the PCB for process 0, and do
    any other initialization that is needed. 
    */
    this->pcbArray.push_back(new Version2PCB());
}

Version2::~Version2() {
    /* Destructor. If you allocated anything with "new" during
    the lifetime of this object, and you haven't yet "delete"d
    it, "delete" it (using the "delete" keyword) here.
    */
    for (auto& p : this->pcbArray) {
        delete p;
    }
}

/* Creates a new child process of process with ID parentPid. 
*/
int Version2::create(int parentPid) {
    // If parentPid is not in the process hierarchy, do nothing; 
    // your code may return an error code or message in this case,
    // but it should not halt.

    // Assuming you've found the PCB for parentPid in the PCB array:
    // 1. Allocate and initialize a free PCB object from the array
    //    of PCB objects

    // 2. Connect the new PCB object to its parent, its older
    //    sibling (if any), and its younger sibling (if any)
    
    if (parentPid > this->pcbArray.size() - 1 || parentPid < 0  || this->pcbArray[parentPid] == nullptr) {
        return 1;
    }

    int pid = this->pcbArray.size();

    this->pcbArray.push_back(new Version2PCB(parentPid));
    
    if (this->pcbArray[parentPid]->getFirstChild() == -1) {
        this->pcbArray[parentPid]->setFirstChild(pid);
    }
    else {
        int lastChild = this->pcbArray[parentPid]->getFirstChild();
        while (this->pcbArray[lastChild]->getYoungerSibling() != -1) {
            lastChild = this->pcbArray[lastChild]->getYoungerSibling();
        }

        this->pcbArray[lastChild]->setYoungerSibling(pid);
        this->pcbArray[pid]->setOlderSibling(lastChild);
    }

    // You can decide what the return value(s), if any, should be.
    return 0; // often means "success" or "terminated normally"
}

/* Recursively destroys the process with ID parentPid and all of
    its descendant processes (child, grandchild, etc.).
*/
int Version2::destroy(int targetPid) {
    // If targetPid is not in the process hierarchy, do nothing; 
    // your code may return an error code or message in this case,
    // but it should not halt

    // Assuming you've found the PCB for targetPid in the PCB array:
    // 1. Recursively destroy all descendants of targetPid, if it
    //    has any, and mark their PCBs as "free" in the PCB array 
    //    (i.e., deallocate them)

    // 2. Adjust connections within the hierarchy graph as needed to
    //    re-connect the graph

    // 3. Deallocate targetPid's PCB and mark its PCB array entry
    //    as "free"

    
    if (targetPid > this->pcbArray.size() - 1 || targetPid < 0 || this->pcbArray[targetPid] == nullptr) {
        return 1;
    }

    int child = this->pcbArray[targetPid]->getFirstChild();
    while (child != -1) {
        int ys = this->pcbArray[child]->getYoungerSibling();
        destroy(child);
        child = ys;
    }

    int os = this->pcbArray[targetPid]->getOlderSibling();
    int ys = this->pcbArray[targetPid]->getYoungerSibling();
    int parent = this->pcbArray[targetPid]->getParent();
    if (os != -1) {
        this->pcbArray[os]->setOlderSibling(ys);
    }
    else if (parent != -1) {
        this->pcbArray[parent]->setFirstChild(ys);
    }

    if (ys != -1) {
        this->pcbArray[ys]->setOlderSibling(os);
    }

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
void Version2::showProcessInfo() {
    for (int i = 0; i < this->pcbArray.size(); i++) {
        if (this->pcbArray[i] == nullptr) {
            continue;
        }

        Version2PCB* p = this->pcbArray[i];
        
        std::cout << "Process " << i << ": parent is " << p->getParent() << " and ";
        int child = p->getFirstChild();
        
        if (child == -1) {
            std::cout << "has no children" << std::endl;
            continue;
        }

        std::cout << "children are";
        while (child != -1) {
            std::cout << ' ' << child;
            child = this->pcbArray[child]->getYoungerSibling();
        }
        std::cout << std::endl;
    }
}

/* If you need or want more functions, feel free to add them. */

void Version2::deletePCBs() {
    for (auto& p : this->pcbArray) {
        delete p;
    }
}

void Version2::resetPCBArray() {
    this->deletePCBs();
    this->pcbArray.clear();
}