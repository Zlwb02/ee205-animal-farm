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
#include "Cat.h"
#include "catDatabase.h"

extern NumCats currentCatNum; // Declared externally in catDatabase.c

int deleteAllCats(){
    while(catDatabaseHeadPointer){
        deleteCat(catDatabaseHeadPointer);
        return 0;
    }
}

int deleteCat(const Cat* index){
    //If the cat to be deleted is the last cat...
    if( index == catDatabaseHeadPointer ) {
      catDatabaseHeadPointer = catDatabaseHeadPointer->next ;
      delete index ;
      currentCatNum--;
      return 0 ;
   }



    Cat* iCat = catDatabaseHeadPointer;
    while(iCat != nullptr){
        if(iCat->next == index){
            iCat->next = index->next;
            delete index;
            currentCatNum --;
            return 0;
        }
        iCat = iCat->next;
    }
    return 0;//??
}
