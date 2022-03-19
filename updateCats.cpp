///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   18_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdbool.h> //For bool data type
#include <stdio.h> //For printing
#include <stdlib.h>
#include <string.h> //For strcpy
#include "catDatabase.h"
#include "config.h"
#include "updateCats.h"

extern Cat_index currentCatNum; // Declared externally in catDatabase.c

int updateCatName(const int index, const char newName[]){
    if(isNameValid(newName) == true){
        strcpy(catdb[index].name, newName);
        return 0;
    }
    return -1;
}//End of upDateCatName

int fixCat(const Cat_index index){
    if( isFixingCatPossible(index) == false){
        fprintf(stderr,"%s: %s has already been fixed... Thats not good... ", PROGRAM_NAME, catdb[index].name);
        return -1;
    }
    catdb[index].isFixed = true;
    return 0;
}//End of fixCat

int updateCatWeight(const Cat_index index, const double newWeight){
    if(isWeightValid(newWeight) == true){
        catdb[index].weight = newWeight;
        return 0;
    }
    return -1;
}//End of updateCatWeight

int updateCatCollar1(const Cat_index index, const Color newCatCollar1){
    if( isCollarValid(newCatCollar1, catdb[index].collarColor2) == true){
        catdb[index].collarColor1 = newCatCollar1;
        return 0;
    }
    return -1;
}//End of updateCatCollar1

int updateCatCollar2(const Cat_index index, const Color newCatCollar2){
    if( isCollarValid(catdb[index].collarColor1, newCatCollar2) == true ){
        catdb[index].collarColor2 = newCatCollar2;
        return 0;
    }
    return -1;
}//End of updateCatCollar2

int updateLicense(const Cat_index index, const License newLicense){
    if (isLicenseValid(newLicense) == true){
        catdb[index].license = newLicense;
        return 0;
    }
    return -1;
}//End of updateLicense

int updateBirthday(const Cat_index index, const char birthdayString[]){
    Birthday birthday = makeBirthday(birthdayString);//Convert birthday string to struct tm
    if(isBirthdayValid(birthday) == true){
        catdb[index].birthday = birthday;
        return 0;
    }
    return -1;
}
