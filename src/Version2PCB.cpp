#include "../headers/Version2PCB.h"

Version2PCB::Version2PCB() : parent(-1), firstChild(-1), youngerSibling(-1), olderSibling(-1) { }

Version2PCB::Version2PCB(int parent) : Version2PCB() { 
    this->parent = parent;
}

Version2PCB::Version2PCB(int parent, int youngerSibling) : Version2PCB(parent) { 
    this->youngerSibling = youngerSibling;
}

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

// Setters
void Version2PCB::setFirstChild(int firstChild) {
    this->firstChild = firstChild;
}

void Version2PCB::setYoungerSibling(int youngerSibling) {
    this->youngerSibling = youngerSibling;
}

void Version2PCB::setOlderSibling(int olderSibling) {
    this->olderSibling = olderSibling;
}