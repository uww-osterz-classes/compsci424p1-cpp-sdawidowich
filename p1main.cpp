/* COMPSCI 424 Program 1
   Name:
   
   p1main.cpp: contains the main function for this program.

   This is a template. Feel free to edit any of these files, even
   these pre-written comments or my provided code. You can add any
   classes, methods, and data structures that you need to solve the
   problem and display your solution in the correct format.
*/

// You will probably need to add more #include directives.
// Remember: use <angle brackets> for standard C++ headers/libraries
// and "double quotes" for headers in the same directory as this file.
#include <iostream>
#include "version1.h" // file containing Version 1 code
#include "version2.h" // file containing Version 2 code

int main(int argc, char *argv[]) {
   // Main program goes here. The required steps have been copied into
   // this file as comments. Feel free to add more comments to help
   // you understand your code, or for any other reason.

   // 1. Ask the user to enter commands of the form "create N", 
   //   "destroy N", or "end", where N is an integer between 0 and 15.

   // 2. While the user has not typed "end", continue accepting
   //    commands. Add each command to a list of actions to take while
   //    you run the simulation. 
   // 3. When the user types "end" (or optionally any word that is not
   //    "create" or "destroy"), stop accepting commands and complete
   //    the following steps.
   //
   // Hint: Steps 2 and 3 refer to the same loop. ;-)

   // 4. Create an object of the Version 1 class and an object of the
   //    Version 2 class.

   // 5. Run the command sequence once with the Version 1 object, 
   //    calling its showProcessTree method after each command to show
   //    the changes in the tree after each command.

   // 6. Repeat step 5, but with the Version 2 object.

   // 7. Store the current system time in a variable
   
   // ... then run the command sequence 200 times with Version 1.

   // ... After this, store the new current system time in a second
   //     variable. Subtract the start time from the end time to get
   //     the Version 1 running time, then display the Version 1
   //     running time.

   // 8. Repeat step 7, but with the Version 2 object.

   // Don't forget to delete anything that you created with "new"!

   cout << "Builds without errors and runs to completion.\n";

   return 0; // tells the OS that the program terminated normally
}
