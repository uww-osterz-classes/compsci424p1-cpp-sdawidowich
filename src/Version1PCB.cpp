#include "Version1PCB.h"

// Getters

int Version1PCB::getParent() {
    return this->parent;
}

std::list<int> Version1PCB::getChildren() {
    return this->children;
}
