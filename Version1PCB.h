#pragma once
#include <iostream>
#include <list>

class Version1PCB {
private:
    int parent;
    std::list<int> children;

public:
    int getParent();
    std::list<int> getChildren();
};