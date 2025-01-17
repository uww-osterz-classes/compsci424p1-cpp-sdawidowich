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
#include <string>
#include <sstream>
#include <ctime>
#include "./headers/version1.h" // file containing Version 1 code
#include "./headers/version2.h" // file containing Version 2 code

enum class Action : short {
   CREATE, DESTROY
};

int main(int argc, char *argv[]) {
   // Main program goes here. The required steps have been copied into
   // this file as comments. Feel free to add more comments to help
   // you understand your code, or for any other reason.

   // 1. Ask the user to enter commands of the form "create N", 
   //   "destroy N", or "end", where N is an integer between 0 and 15.
   std::cout << "Enter commands in the form 'create N', 'destroy N', or 'end', where N is and integer between 0 and 15." << std::endl;

   // 2. While the user has not typed "end", continue accepting
   //    commands. Add each command to a list of actions to take while
   //    you run the simulation. 
   // 3. When the user types "end" (or optionally any word that is not
   //    "create" or "destroy"), stop accepting commands and complete
   //    the following steps.
   //
   // Hint: Steps 2 and 3 refer to the same loop. ;-)

   std::vector<std::pair<Action, int>> commandList;
   
   std::string command;
   while(true) {
      std::getline(std::cin, command);

		std::stringstream ss(command);

      // Get action
		std::string action;
		std::getline(ss, action, ' ');

      // Get integer
      std::string str_n;
		std::getline(ss, str_n, ' ');
      
      // Break out of loop if action is not create or destroy or if no integer was provided.
      if ((action != "create" && action != "destroy") || str_n == "") {
         break;
      }

      // Convert integer string to integer type, add action to command list
      int n = std::stoi(str_n);
      if (action == "create") {
         commandList.push_back({ Action::CREATE, n });
      }
      else {
         commandList.push_back({ Action::DESTROY, n });
      }

   }

   // 4. Create an object of the Version 1 class and an object of the
   //    Version 2 class.
   Version1* v1 = new Version1();
   Version2* v2 = new Version2();

   // 5. Run the command sequence once with the Version 1 object, 
   //    calling its showProcessTree method after each command to show
   //    the changes in the tree after each command.

   std::cout << "Version 1" << std::endl;
   for (auto& c : commandList) {
      if (c.first == Action::CREATE) {
         v1->create(c.second);
      }
      else {
         v1->destroy(c.second);
      }

      v1->showProcessInfo();
   }
   

   // 6. Repeat step 5, but with the Version 2 object.
   std::cout << "Version 2" << std::endl;
   for (auto& c : commandList) {
      if (c.first == Action::CREATE) {
         v2->create(c.second);
      }
      else {
         v2->destroy(c.second);
      }

      v2->showProcessInfo();
   }

   // 7. Store the current system time in a variable
   
   // ... then run the command sequence 200 times with Version 1.
   std::clock_t t1 = std::clock();
   
   for (int i = 0; i < 200; i++) {
      v1->resetPCBArray();
      for (auto& c : commandList) {
         if (c.first == Action::CREATE) {
            v1->create(c.second);
         }
         else {
            v1->destroy(c.second);
         }
      }
   }
   
   // ... After this, store the new current system time in a second
   //     variable. Subtract the start time from the end time to get
   //     the Version 1 running time, then display the Version 1
   //     running time.

   t1 = std::clock() - t1;
   std::cout << "Version 1 executed the command list 200 times in " << t1 << " time units" << std::endl;

   // 8. Repeat step 7, but with the Version 2 object.

   std::clock_t t2 = std::clock();
   
   for (int i = 0; i < 200; i++) {
      v2->resetPCBArray();
      for (auto& c : commandList) {
         if (c.first == Action::CREATE) {
            v2->create(c.second);
         }
         else {
            v2->destroy(c.second);
         }
      }
   }

   t2 = std::clock() - t2;
   std::cout << "Version 2 executed the command list 200 times in " << t2 << " time units" << std::endl;

   delete v1;
   delete v2;

   // Don't forget to delete anything that you created with "new"!

   std::cout << "Builds without errors and runs to completion.\n";

   std::cin.get();

   return 0; // tells the OS that the program terminated normally
}
