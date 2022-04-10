///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   18_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "reportCats.h"
#include "catDatabase.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

extern NumCats currentCatNum; // Declared externally in catDatabase.c
//extern color color;

extern const char* toIsFixedName (const bool isFixed){
    if(isFixed){
        return "true";
    } else {
        return "false";
    }
}//End of toIsFixedName

extern const char* toColorName (const Color color ) { //BLACK,WHITE,PURPLE,BLUE,AQUA,GREEN,YELLOW,ORANGE,RED,PINK,BROWN,RAINBOW,OTHER
    switch(color){
        case 0:	return "Black";	break;
        case 1:	return "White";	break;
        case 2:	return "Purple"; break;
        case 3:	return "Blue";	break;
        case 4:	return "Aqua";	break;
        case 5:	return "Green";	break;
        case 6:	return "Yellow"; break;
        case 7:	return "Orange"; break;
        case 8: return "Red";	break;
        case 9: return "Pink";	break;
        case 10:return "brown";	break;
        case 11:return "Rainbow";break;
        case 12:return "Other";  break;
        default:return "How'd you even do this??";	break;
    }//End of switch
}//End of toColorName

extern const char* toBreedName ( const Breed breed){ //UNKNOWN_BREED,MAINE_COON,MANX,SHORTHAIR,PERSIAN,SPHYNX
    switch(breed){
        case 0: return "Unknown Breed"; break;
        case 1: return "Maine Coon"; break;
        case 2: return "Manx"; break;
        case 3: return "Shorthair"; break;
        case 4: return "Persian"; break;
        case 5: return "Sphynx"; break;
        default: return "How'd you even do this??"; break;
    }//End of switch
}//End of toBreedName

extern const char* toGenderName ( const Gender gender){ //UNKNOWN_GENDER,MALE,FEMALE
    switch(gender){
        case 0: return "Unknown"; break;
        case 1: return "Male"; break;
        case 2: return "Female"; break;
        default: return "How'd you even do this??"; break;
    }//End of Switch
}//End of toGenderName


//Prints the data stored in the array of a specific cat given an index
int printCat(const NumCats index){
    char dateFormatted[10];//Used to store formatted Date for printf
    strftime(dateFormatted,sizeof(dateFormatted), "%d/%m/%y", &catdb[index].birthday);//Formats datefrom struct tm number as dd/mm/yy per spec.
    if(index > currentCatNum){ //Makes sure the input cat index is in the range
        fprintf(stderr, "%s: Bad cat at index %ld",PROGRAM_NAME,index);
        //exit(EXIT_FAILURE);
        return -1;
    }

    else{
        printf("cat index= %-6lu\t" , index;
        printf("name= %-15s",catdb[index].name);
        printf("Gender= %-10s", toGenderName(catdb[index].gender));
        printf("Breed= %-12s",toBreedName(catdb[index].breed));
        printf("isFixed= %-6s", toIsFixedName(catdb[index].isFixed));
        printf("weight= %-12f",catdb[index].weight);
        printf("collar1= %-12s", toColorName(catdb[index].collarColor1)); //passes color enum number into toColorName to be displayed as pointer
        printf("collar2= %-12s", toColorName(catdb[index].collarColor2)); //...
        printf("License= %-12llu",catdb[index].license);
        printf("birthday= %s\n",dateFormatted);//Formatted in strftime seen above
        return 0;
    }
}//End of printCat

//Prints all cats in db
int printAllCats(){
    for(NumCats i = 0; i < currentCatNum; i++){
        printCat(i);
    }
    return 0;
}//End of printAllCats

//find cat index given an name
int findCat(const char lookupName[] ){
    bool found = false;
    int foundindex;
    for(NumCats i = 0; i < currentCatNum; i++ ){
        if( strcmp(catdb[i].name, lookupName ) == 0){
            found = true;
            foundindex = i;
        }
    }//End of for loop
    if( found == true ){
        return foundindex;
    }
    else{
        fprintf(stderr, "%s: Cat %s not found.\n",PROGRAM_NAME, lookupName);
        //exit(EXIT_FAILURE);
        return -1;
    }
}//End of findCat
