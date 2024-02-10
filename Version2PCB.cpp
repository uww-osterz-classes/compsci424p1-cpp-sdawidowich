#include "Version2PCB.h"

// Getters

int Version2PCB::getParent() {
    return this->parent;
}

int Version2PCB::getFirstChild() {
    return this->firstChild;
}

int Version2PCB::getYoungerSibling() {
    return this->youngerSibling;
}

int Version2PCB::getOlderSibling() {
    return this->olderSibling;
}