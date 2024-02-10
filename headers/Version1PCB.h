#pragma once
#include <iostream>
#include <list>

class Version1PCB {
private:
    int parent;
    std::list<int> children;

public:
    Version1PCB();
    Version1PCB(int parent);

    int getParent();
    std::list<int> getChildren();

    void addChild(int targetPid);
    void removeChild(int targetPid);
};