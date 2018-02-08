#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H

#include <string>
#include <vector>
#include <list>
#include <fstream>

#include "Names.hpp"

class NameGenerator
{
   std::vector<std::string> listOfRaces;
   std::vector<Names> namesTable;

public:
   enum NameGenerationStatus_E
   {
      NoError = 0,
      Error_FileWasNotOpened,
      Error_NameGenerationFailed,
      Error_Unknown
   };

   NameGenerator();
   ~NameGenerator();

   NameGenerationStatus_E ReadNameDatabase(std::string filename);
   NameGenerationStatus_E GenerateName(std::string givenRace, std::string givenGender,
                                       std::string *generatedName);
   bool GetAvailableRaces(std::vector<std::string> *retList);

private:
   NameGenerationStatus_E  generateName(std::string givenRace, std::string givenGender,
                                        std::string *generatedName);
   bool addToRaceList(std::string givenRace);
};

#endif // ndef NAMEGENERATOR_H