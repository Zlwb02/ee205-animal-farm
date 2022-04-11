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
#include "catDatabase.h"
#include "Cat.h"
#include <iostream>

using namespace std;
bool addCat(Cat* newCat){
    cout << "newCat Validatedd " << PROGRAM_NAME << endl ;
    //newCat->validate();
    cout << "newCat Validated " << PROGRAM_NAME << endl ;
    newCat->next=catDatabaseHeadPointer;
    catDatabaseHeadPointer = newCat;
    return true;
}

