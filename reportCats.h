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

int printCat(const NumCats index);
int printAllCats();
int findCat(const char lookupName[]);