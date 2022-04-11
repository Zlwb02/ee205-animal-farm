///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   18_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <stdbool.h> //Defines bool data type for isFixed in struct Cat
#include <stddef.h>  // Allows for size_t. Could also use stdio.h if needed later
#include <time.h>
#include "config.h" // For MAX's'
#include "Cat.h"




extern void initializeDatabase();
extern bool validateDatabase();
//extern struct Cat catdb[MAX_CATS]; //This doesnt allocate any memory, just says this fn is declared in catDatabase.c
extern Cat* catDatabaseHeadPointer;


//Function Declarations
/*
extern bool isdbFull();
extern bool isNameValid(const char name[]);
extern bool isWeightValid(Weight weight);
extern bool isLicenseValid(License license);
extern bool isCollarValid(Color collarColor1, Color collarColor2);
extern bool isFixingCatPossible(NumCats index);
extern Birthday makeBirthday(const char birthday[]);
extern bool isBirthdayValid(Birthday birthday);
 */