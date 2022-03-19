///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.h
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

extern int updateCatName(const int index, const char newName[]);
extern int fixCat(const Cat_index index);
extern int updateCatWeight(const Cat_index index, const double newWeight);
extern int updateCatCollar1(const Cat_index index, const Color newcatCollar1);
extern int updateCatCollar2(const Cat_index index, const Color newcatCollar2);
extern int updateLicense(const Cat_index index, const License newlicense);
extern int updateBirthday(const Cat_index index, const char birthdayString[]);