///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   18_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "deleteCats.h"

#include "catDatabase.h"
#include <stdio.h>//For printf
#include <string.h>//For memset

extern Cat_index currentCatNum; // Declared externally in catDatabase.c

int deleteAllCats(){
    memset(catdb,0,sizeof(catdb));//Resets all data in catdb to 0
    currentCatNum = 0;
    return 0;
}

int deleteCat(const Cat_index index){
    if( index > currentCatNum ){
        fprintf(stderr, "%s: Cannot Delete this item at index %d as it's outside of the database.",PROGRAM_NAME, (int)index);
        return -1;
    }
    else{
        for(Cat_index i = index - 1; i < currentCatNum - 1; i++){
            catdb[i]= catdb[i+1]; //Move the next element(i+1) one down (i)
        }
        currentCatNum -=1;//Moves the index back one
        return 0;
    }
}
