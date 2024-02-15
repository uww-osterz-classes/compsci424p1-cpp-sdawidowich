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
    Version2PCB();
    Version2PCB(int parent);
    Version2PCB(int parent, int youngerSibling);

    int getParent();
    int getFirstChild();
    int getYoungerSibling();
    int getOlderSibling();

    void setFirstChild(int firstChild);
    void setYoungerSibling(int youngerSibling);
    void setOlderSibling(int olderSibling);
};