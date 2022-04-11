///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   09_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once


#include "config.h"
//#include "catDatabase.h"

//Defines the enum's
typedef enum {UNKNOWN_GENDER,MALE,FEMALE} Gender;
typedef enum {UNKNOWN_BREED,MAINE_COON,MANX,SHORTHAIR,PERSIAN,SPHYNX} Breed;
typedef enum {BLACK,WHITE,PURPLE,BLUE,AQUA,GREEN,YELLOW,ORANGE,RED,PINK,BROWN,RAINBOW,OTHER} Color;


//Defines aliases
typedef size_t NumCats; // Sets a new datatype , NumCats, as alias to size_t
typedef float Weight;
typedef unsigned long long License;
typedef struct tm Birthday;

class Cat {
//----------------------------Members-------------------------------
public: //Public Member(s)
    Cat*        next;
protected://Protected Members
    //Data type           Data name
    char                *name;
    Gender              gender;         //enum genders declared above
    Breed               breed;          //enum breeds declared above
    bool                isFixed;
    Weight              weight;
    //Color               collarColor1;   //enum color declared above
    //Color               collarColor2;   //...
    //unsigned long long  license;
    //Birthday            birthday;       //Used for storing birthday

//--------------------------Constructors-----------------------------
public://Public Constructors
    Cat();
    Cat( const char* newName,  Gender newGender,
         Breed newBreed,  Weight newWeight );
private:
    void clearCatData();

//--------------------------Methods----------------------------------
public://Public Methods
    //Setters
    void setName(const char *newName);
    void setWeight( Weight newWeight);
    void setGender( Gender newGender);
    void setBreed( Breed newBreed);

    //Getters
    char * getName() const;
    Gender getGender() const;
    Breed getBreed() const;
    Weight getWeight() const;
    bool getIsFixed() const;

    //Validators
    bool validate() const;
    bool validateName(const char *newName) const;
    bool validateGender( Gender newGender) const;
    bool validateBreed( Breed newBreed) const;
    bool validateWeight( Weight newWeight) const;
    //Other
    bool print() const noexcept;
    void fixCat();


};//End of Cat class




