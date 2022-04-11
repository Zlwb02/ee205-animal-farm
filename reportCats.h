///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   18_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "catDatabase.h"

int printCat( NumCats index);
int printAllCats();
int findCat( char lookupName[]);
const char* toIsFixedName(bool isFixed);
const char* toColor(Color color);
const char* toBreedName(Breed breed);
const char* toGenderName(Gender gender);


