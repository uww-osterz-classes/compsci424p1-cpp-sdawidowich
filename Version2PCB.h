#pragma once
#include <iostream>
#include <list>

class Version2PCB {
private:
    int parent;
    int firstChild;
    int youngerSibling;
    int olderSibling;

public:
    int getParent();
    int getFirstChild();
    int getYoungerSibling();
    int getOlderSibling();
};