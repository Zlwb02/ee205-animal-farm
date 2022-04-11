///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.h
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
#include "Cat.h"

//int addCat(const char name[], const Gender gender, const Breed breed, const bool isFixed, const Weight weight, const Color collarColor1, const Color collarColor2, const License license, const char birthday[]);
bool addCat(Cat* newCat);