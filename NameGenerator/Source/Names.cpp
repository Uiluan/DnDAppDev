#include "Names.hpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

/*!
 * Constructor for the Names object. One Names object contains a single race to indicate what race
 * the names belong to. One Names object holds a list of male, female, and last names for the
 * indicated race.
 */
Names::Names()
{
   srand(time(NULL));
}

/*!
 * Destructor for the names object.
 */
Names::~Names()
{

}

/*!
 * Assigns a given race string to the race field for the name. The race field indicates what
 * race the name belongs to.
 *
 * @param race - Race the name belongs to, e.g. Human, Elf, Dwarf, etc...
 *
 * @return Boolean indicating whether the assignment was successful or not.
 */
bool Names::AssignRace(string givenRace)
{
   race = givenRace;

   return true;
}

/*!
 * Adds a male name to the list of male names for the object.
 *
 * @param name - Name to add to the list.
 *
 * @return Boolean indicating whether the name was successfully added or not.
 */
bool Names::AddMaleName(string givenName)
{
   maleNames.push_back(givenName);

   return true;
}

/*!
 * Adds a female name to the list of female names for the object.
 *
 * @param name - Name to add to the list.
 *
 * @return Boolean indicating whether the name was successfully added or not.
 */
bool Names::AddFemaleName(string givenName)
{
   femaleNames.push_back(givenName);
}

/*!
 * Adds a last name to the list of last names for the object.
 *
 * @param name - Name to add to the list.
 *
 * @return Boolean indicating whether the name was successfully added or not.
 */
bool Names::AddLastName(string givenName)
{
   lastNames.push_back(givenName);
}

/*!
 * Gets the race assigned to the object.
 *
 * @return String containing race assigned to the object.
 */
string Names::GetRace()
{
   return race;
}

/*!
 * Gets a random name from the list of male names for the object.
 *
 * @return String containing the random name. Empty string if the list of names is empty.
 */
string Names::GetRandomMaleName()
{
   string retString = "";

   if(!maleNames.empty())
   {
      int randomIndex = rand() % maleNames.size();

      retString = maleNames[randomIndex];
   }

   return retString;
}

/*!
 * Gets a random name from the list of female names for the object.
 *
 * @return String containing the random name. Empty string if the list of names is empty.
 */
string Names::GetRandomFemaleName()
{
   string retString = "";

   if(!femaleNames.empty())
   {
      int randomIndex = rand() % femaleNames.size();

      retString = femaleNames[randomIndex];
   }

   return retString;
}

/*!
 * Gets a random name from the list of last names for the object.
 *
 * @return String containing the random name. Empty string if the list of names is empty.
 */
string Names::GetRandomLastName()
{
   string retString = "";

   if(!lastNames.empty())
   {
      int randomIndex = rand() % lastNames.size();

      retString = lastNames[randomIndex];
   }

   return retString;
}
