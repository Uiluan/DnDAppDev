#include "NameGenerator.hpp"

#include <iostream>
#include <sstream>

using namespace std;

/*!
 *
 */
NameGenerator::NameGenerator()
{

}

/*!
 *
 */
NameGenerator::~NameGenerator()
{

}

/*!
 *
 */
NameGenerator::NameGenerationStatus_E NameGenerator::ReadNameDatabase(string filename)
{
   string currentLine;
   ifstream nameFile;

   NameGenerator::NameGenerationStatus_E retVal = NameGenerator::Error_Unknown;

   nameFile.open(filename);

   if(nameFile.is_open())
   {
      // First line is race names. Parse this line and create  a list of name objects accordingly.
      getline(nameFile, currentLine);

      // Create a temporary stringstream so we can use getline on the current line
      stringstream tempStream(currentLine);

      while(tempStream.good())
      {
         // Parse line via comma seperation
         string substring;

         getline(tempStream, substring, ',');

         if(!substring.empty())
         {
            // Add race to the list of races
            addToRaceList(substring);
         }
      }


      // Second line is gender. Each "race" division shall have a male, female, and last name
      // fields, in that order. We don't need to use this line, so we will then start getting
      // the names.
      getline(nameFile, currentLine);

      // Begin getting names
      while(!nameFile.eof())
      {
         // Get line of names
         getline(nameFile, currentLine);

         // Create a temporary stringstream so we can use getline on the current line
         stringstream tempStream(currentLine);

         // Create the name database
         for(int raceIndex = 0;
             ((raceIndex < listOfRaces.size()) && tempStream.good());
             raceIndex++)
         {
            string substring;

            // Get first name and add to male names
            getline(tempStream, substring, ',');

            if(!substring.empty())
            {
               namesTable[raceIndex].AddMaleName(substring);
            }

            // Get second name and add to female names
            getline(tempStream, substring, ',');

            if(!substring.empty())
            {
               namesTable[raceIndex].AddFemaleName(substring);
            }

            // Get third name and add to last names
            getline(tempStream, substring, ',');

            if(!substring.empty())
            {
               namesTable[raceIndex].AddLastName(substring);
            }
         }

         retVal = NameGenerator::NoError;
      }
   }
   else
   {
      // File could not be opened.
      retVal = NameGenerator::Error_FileWasNotOpened;
   }

   nameFile.close();
}

/*!
 *
 */
NameGenerator::NameGenerationStatus_E NameGenerator::GenerateName(string givenRace,
                                                                  string givenGender,
                                                                  string *generatedName)
{
   NameGenerator::NameGenerationStatus_E status = generateName(givenRace, givenGender, generatedName);

   return status;
}

/*!
 *
 */
bool NameGenerator::GetAvailableRaces(vector<string> *retList)
{
   *retList = listOfRaces;

   return true;
}

// Private Functions ===============================================================================

/*
 * Generates a name (first and last) for the given race and gender.
 */
NameGenerator::NameGenerationStatus_E  NameGenerator::generateName(string givenRace,
                                                                   string givenGender,
                                                                   string *generatedName)
{
   NameGenerator::NameGenerationStatus_E retStatus = NameGenerator::Error_Unknown;

   bool indexFound = false;

   // Get index for race
   for(int i = 0; ((i < listOfRaces.size()) && false == indexFound); i++)
   {
      if(namesTable[i].GetRace().compare(givenRace) == 0)
      {
         if(givenGender.compare("male") == 0)
         {
            *generatedName = namesTable[i].GetRandomMaleName() + " " +
                             namesTable[i].GetRandomLastName();
         }
         else if(givenGender.compare("female") == 0)
         {
            *generatedName = namesTable[i].GetRandomFemaleName() + " " +
                             namesTable[i].GetRandomLastName();
         }
         else
         {
            retStatus = NameGenerator::Error_NameGenerationFailed;
         }

         indexFound = true;
      }
   }

   if(false == indexFound)
   {
      retStatus = NameGenerator::Error_NameGenerationFailed;
   }

   return retStatus;
}

/*
 * Adds a given value to the list of races.
 */
bool NameGenerator::addToRaceList(string givenRace)
{
   Names tempName;

   tempName.AssignRace(givenRace);
   namesTable.push_back(tempName);

   listOfRaces.push_back(givenRace);

   return true;
}
