#ifndef NAMES_H
#define NAMES_H

#include <string>
#include <vector>

class Names
{
   std::string race;

   std::vector<std::string> maleNames;
   std::vector<std::string> femaleNames;
   std::vector<std::string> lastNames;

public:
   Names();
   ~Names();

   bool AssignRace(std::string race);
   bool AddMaleName(std::string name);
   bool AddFemaleName(std::string name);
   bool AddLastName(std::string name);

   std::string GetRace();

   std::string GetRandomMaleName();
   std::string GetRandomFemaleName();
   std::string GetRandomLastName();
};

#endif // ndef NAMES_H