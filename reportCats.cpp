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

extern Cat_index currentCatNum; // Declared externally in catDatabase.c
//extern color color;

extern char* toColor ( const Color color ) { //BLACK,WHITE,PURPLE,BLUE,AQUA,GREEN,YELLOW,ORANGE,RED,PINK,BROWN,RAINBOW,OTHER
    switch(color){
        case 0:	return (char*)"Black";	break;
        case 1:	return (char*)"White";	break;
        case 2:	return (char*)"Purple";break;
        case 3:	return (char*)"Blue";	break;
        case 4:	return (char*)"Aqua";	break;
        case 5:	return (char*)"Green";	break;
        case 6:	return (char*)"Yellow";break;
        case 7:	return (char*)"Orange";break;
        case 8: return (char*)"Red";	break;
        case 9: return (char*)"Pink";	break;
        case 10:return (char*)"brown";	break;
        case 11:return (char*)"Rainbow";break;
        case 12:return (char*)"Other"	;break;
        default:return (char*)"How'd you even do this??";	break;
    }//End of switch
}//End of toColor

//Prints the data stored in the array of a specific cat given an index
int printCat(const Cat_index index){
    char dateFormatted[10];//Used to store formatted Date for printf
    strftime(dateFormatted,sizeof(dateFormatted), "%d/%m/%y", &catdb[index].birthday);//Formats datefrom struct tm number as dd/mm/yy per spec.
    if(index > currentCatNum){
        fprintf(stderr, "%s: Bad cat at index %ld",PROGRAM_NAME,index);
        //exit(EXIT_FAILURE);
        return -1;
    }
    else{ //The print statements should be fixed to accomidate longer values next to shorter values; the tab(\t) will preform imperfectly
        printf("cat index= %-6lu\t",index);
        printf("name= %-15s",catdb[index].name);
        printf("Gender= %-6d",catdb[index].gender);
        printf("Breed= %-6d",catdb[index].breed);
        printf("isFixed= %-6d",catdb[index].isFixed);
        printf("weight= %-12f",catdb[index].weight);
        printf("collar1= %-12s",toColor(catdb[index].collarColor1)); //passes color enum number into toColor to be displayed as pointer
        printf("collar2= %-12s",toColor(catdb[index].collarColor2)); //...
        printf("License= %-12llu",catdb[index].license);
        printf("birthday= %s\n",dateFormatted);//Formatted in strftime seen above
        return 0;
    }
}//End of printCat

//Prints all cats in db
int printAllCats(){
    for(Cat_index i = 0; i < currentCatNum; i++){
        printCat(i);
    }
    return 0;
}//End of printAllCats

//find cat index given an name
int findCat(const char lookupName[] ){
    bool found = false;
    int foundindex;
    for(Cat_index i = 0; i < currentCatNum; i++ ){
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
