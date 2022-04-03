///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   18_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "addCats.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> //Declares bool type
#include "catDatabase.h"

extern NumCats currentCatNum; // Declared externally in catDatabase.c as type size_t

//Used to add cat to the database
int addCat(const char name[], const Gender gender, const Breed breed, const bool isFixed, const Weight weight, const Color collarColor1, const Color collarColor2, const License license, const char birthdayString[]){
    Birthday birthday = makeBirthday(birthdayString);//Convert birthday string to struct tm
    if( (isdbFull() == false) && (isNameValid(name) == true) && (isWeightValid(weight) == true) && (isCollarValid(collarColor1, collarColor2) == true) && (isLicenseValid(license) == true) && (isBirthdayValid(birthday) == true) ){
        strcpy(catdb[currentCatNum].name, name);
        catdb[currentCatNum].gender			= gender;
        catdb[currentCatNum].breed			= breed;
        catdb[currentCatNum].isFixed		= isFixed;
        catdb[currentCatNum].weight 		= weight;
        catdb[currentCatNum].collarColor1   =collarColor1;
        catdb[currentCatNum].collarColor2	=collarColor2;
        catdb[currentCatNum].license		=license;
        catdb[currentCatNum].birthday       =birthday;
        currentCatNum += 1;
        return currentCatNum-1;// -1 to get last cat in db, current cat num holds next cat index avalible
    }//End of if
    return -1;//Return -1 is adding cat failed
}//End of addCat
