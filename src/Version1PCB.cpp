#include "Version1PCB.h"

Version1PCB::Version1PCB() : parent(-1), children(std::list<int>()) { }
Version1PCB::Version1PCB(int parent) : Version1PCB() { 
    this->parent = parent;
}

// Getters
int Version1PCB::getParent() {
    return this->parent;
}

std::list<int> Version1PCB::getChildren() {
    return this->children;
}

// Setters
void Version1PCB::addChild(int targetPid) {
    this->children.push_back(targetPid);
}

void Version1PCB::removeChild(int targetPid) {
    for (auto child = this->children.begin(); child != this->children.end(); child++) {
        if (*child == targetPid) {
            this->children.erase(child);
            return;
        }
    }
}