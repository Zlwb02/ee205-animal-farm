///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   09_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cstring>
#include "Cat.h"
#include "reportCats.h"
#include "catDatabase.h"
#include <stdexcept>//Used in validators for throwing exceptions
#include <cassert>
#include <iostream>
#include <iomanip>



using namespace std;
Cat::Cat() {
    clearCatData();
}

Cat::Cat(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight) {
    setName( newName);
    setGender( newGender);
    setBreed( newBreed);
    setWeight( newWeight);
    //Default isFixed = false
    //All other fields should be zero'd out
    //assert(validate());
}

//---------------------------------------------------Setters----------------------------------------------------------
void Cat::setName(const char *newName) {
    if(validateName(newName)) { ;
        //strcpy(name, newName);
    }
}

void Cat::setGender(const Gender newGender) {
    if(validateGender(newGender)) { ;
        Cat::gender = newGender;
    }
}

void Cat::setBreed(const Breed newBreed) {
    if(validateBreed(newBreed)) {
        Cat::breed = newBreed;
    }
}

void Cat::setWeight(const Weight newWeight ) {
    if(validateWeight(newWeight)) {
        Cat::weight = newWeight;
    }
}




//--------------------------------------------Getters------------------------------------------------------------------
char* Cat::getName() const {
    return name;
}

Gender Cat::getGender() const {
    return gender;
}

Breed Cat::getBreed() const {
    return breed;
}

Weight Cat::getWeight() const {
    return weight;
}

bool Cat:: getIsFixed() const {
    return isFixed;
}

//-------------------------------------------Validators----------------------------------------------------------------
bool Cat::validate() const {
    if( validateName(name) && validateGender(gender) && validateBreed(breed) && validateWeight(weight)) {
        return true;
    }
    return false;
}

bool Cat::validateName(const char *newName) const {
    if(newName == nullptr ){ // If name parameter is empty...
        throw invalid_argument(PROGRAM_NAME ": name cannot be empty.");
    }//End of if
    if( strlen(newName) >= MAX_NAME_LENGTH){ //If name parameter is too long...
        throw length_error(PROGRAM_NAME ": The cat's name is too long; must be under 50 characters.");//50 as defined by MAX_NAME_LENGTH
    }//End of if
    return true;//Returns true if all tests pass, otherwise nothing is returned (false)
}

bool Cat::validateGender(const Gender newGender) const {
    if( newGender == UNKNOWN_GENDER){
        throw invalid_argument(PROGRAM_NAME ": The cat's gender can't be unknown.");
    }
    return true;
}

bool Cat::validateBreed(const Breed newBreed) const {
    if( newBreed == UNKNOWN_BREED){
        throw invalid_argument(PROGRAM_NAME ": The cat's breed can't be unknown.");
    }
    return true;
}

bool Cat::validateWeight(const Weight newWeight) const {
    if( newWeight <= 0 || newWeight > MAX_CAT_WEIGHT ){ //If weight less than or equal to zero or unreasonable
        throw invalid_argument(PROGRAM_NAME ": The cat's weight must be greater than zero and reasonable.");
    }
    return true;
}

bool validateIfFixPossible() {
    //if(Cat::isFixed == true){
    //    throw logic_error(PROGRAM_NAME ": The cat has already been fixed, this isn't possible ");
    //}
    return true;//I'd like to check to see if cat has already been fixed but dont know how. Will ask prof
}

//--------------------------------------------------Misc---------------------------------------------------------------
void Cat::clearCatData() {
    memset( name, 0, MAX_NAME_LENGTH);
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    isFixed = false;
    weight = 0;
    next = nullptr;
}

/// Format a line for printing the members of a class
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)
/// @returns true if everything worked correctly. false if something goes
/// wrong
bool Cat::print() const noexcept {
    assert( validate() ) ;
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" ) << getName() << endl ;
    FORMAT_LINE( "Cat", "gender" ) << toGenderName( getGender() ) << endl ;
    FORMAT_LINE( "Cat", "breed" ) << toBreedName( getBreed() ) << endl ;
    FORMAT_LINE( "Cat", "isFixed" ) << toIsFixedName(getIsFixed()) << endl ;
    FORMAT_LINE( "Cat", "weight" ) << getWeight() << endl ;
    return true ;
}





