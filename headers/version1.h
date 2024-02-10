/* COMPSCI 424 Program 1
   Name:
   
   version1.h: contains the code to implement the process creation
   hierarchy for Version 1, which uses linked lists.

   This is a template. Feel free to edit any of these files, even
   these pre-written comments or my provided code. You can add any
   classes, methods, and data structures that you need to solve the
   problem and display your solution in the correct format.

   C++ style note:
   This .h file is set up to include both declarations and code. It's 
   considered good practice for .h files to contain only declarations
   and for most or all non-declaration code to be in .cpp files (which
   #include the relevant .h file(s)). However, if you're not used to
   compiling and linking multiple .cpp (or .cc or .C) files at once, 
   putting both declarations and code in the .h files is easier. 
   
   If you prefer to separate your declarations and code, feel free to
   do that. GitHub Classroom is set up to compile all .cpp, .cc, and
   .C files that are in your repository.
*/

#ifndef VERSION1_H
#define VERSION1_H

// You may need to add more #include directives.
// Remember: use <angle brackets> for standard C++ headers/libraries
// and "double quotes" for headers in the same directory as this file.
#include <iostream>
#include <vector>
#include "./Version1PCB.h"

class Version1 {
   private: // it's good OOP practice to make data members private
      std::vector<Version1PCB> pcbArray;

   public:  // all methods are normally public
      Version1();
      ~Version1();

      int create(int parentPid);
      int destroy(int targetPid);
      void showProcessInfo();
};

#endif  // VERSION1_H
