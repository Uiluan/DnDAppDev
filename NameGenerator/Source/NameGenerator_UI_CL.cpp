#include "NameGenerator.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
   NameGenerator generator;
   vector<string> nameList;
   string selectedGender;
   string selectedRace;
   string name;

   int userInput = 0;
   bool userInputInvalid = true;

   // Read the name database
   generator.ReadNameDatabase("C:\\Users\\Robert\\OneDrive\\D&D\\AppDev\\NameGenerator\\NameDatabase.csv");

   // Get the list of names and display them to the user.,
   generator.GetAvailableRaces(&nameList);

   cout << endl << "Follow the prompts to generate a name." << endl;

   // Get user input
   while(true)
   {
      cout << endl << "Please select a race to generate a name for (enter the number next to the entry)." << endl << endl;

      // Get race
      while(userInputInvalid)
      {
         for(int i = 0; i < nameList.size(); i++)
         {
            cout << (i + 1) << ". " << nameList.at(i) << endl;
         }

         cout << endl << ">";
         cin >> userInput;

         if((userInput > 0) && (userInput <= nameList.size()))
         {
            userInputInvalid = false;

            selectedRace = nameList.at(userInput - 1);
         }
         else
         {
            cout << "Input was not a valid selection, please select again." << endl;
         }
      }

      userInputInvalid = true;

      cout << endl << "Please select a gender of the race to generate a name for (enter the number next to the entry)." << endl << endl;

      cout << endl << "1. Male" << endl << "2. Female" << endl;

      // Get gender
      while(userInputInvalid)
      {
         cout << endl << ">";
         cin >> userInput;

         if((userInput > 0) && (userInput <= 2))
         {
            userInputInvalid = false;

            switch(userInput)
            {
               case 1:
                  selectedGender = "male";

                  break;

               case 2:
                  selectedGender = "female";

                  break;
            }

            generator.GenerateName(selectedRace, selectedGender, &name);

            cout << endl << name << endl;
         }
         else
         {
            cout << "Input was not a valid selection, please select again." << endl;
         }
      }

      userInputInvalid = true;
   }
}
