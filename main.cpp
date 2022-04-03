///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   18_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "addCats.h"
#include "catDatabase.h"
#include "deleteCats.h"
#include "reportCats.h"
#include "updateCats.h"

#include <stdlib.h>		//For exit Success and exit Failure
#include <assert.h>		//For assert
#include <stdio.h>      // For strings etc

int main(){ // int argc, char* argv[] have been removed as they are not used in this program
    setvbuf(stdout, NULL, _IONBF, 0);//Fixes errors with things being printed out of order
    setvbuf(stdin, nullptr, _IONBF, 0);
    if(DEBUGMODE){
        //-----------------------------------------Check addCats & db-------------------------------------------
        printf("\n----addCats & db checking----");
        addCat( "Loki", MALE, PERSIAN, true, 8.5, BLACK, WHITE, 101, "Jan 31, 2010" ) ;
        addCat( "Milo", MALE, MANX, true, 7.0, BLACK, RED, 102, "Jun 16, 2014" ) ;
        addCat( "Bella", FEMALE, MAINE_COON, true, 18.2, BLACK, BLUE, 103, "Feb 29, 2016" ) ;
        addCat( "Kali", FEMALE, SHORTHAIR, false, 9.2, BLACK, GREEN, 104, "December 14, 2020" ) ;
        addCat( "Trin", FEMALE, MANX, true, 12.2, BLACK, PINK, 105, "August 22, 2017" ) ;
        addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106, "July 30, 2013" ) ;
        //Purposeful error checking
        printf("\n-There should be 8 Different errors below:\n");
        addCat("", MALE, PERSIAN, true, 6.5,AQUA,GREEN,107, "July 4, 2005"); //Name string cannot be empty
        addCat("HappyBirthdayToYou,HappyBirthdayDearProfessorNelsonHappyBirthdayToYou,HappyBirthdayDearProfessorNelson",MALE ,UNKNOWN_BREED, false, 100.8, BLUE, ORANGE, 108, "Sep 16, 2007" ); //Name must be < [MAX_NAME_LENGTH]
        addCat( "Loki", MALE, PERSIAN, true, 8.5, PINK, PURPLE, 109, "April 14, 2022" ); //Cats can't have same name
        addCat( "Mauritus", MALE, PERSIAN, true, (double)0 , RED, YELLOW, 110, "Oct 12, 2009"); //Cats weight must be > 0
        addCat( "Mochi", FEMALE, SHORTHAIR, false, 12.4, PURPLE, RED, 111, "Jan 33, 2022") ;//Date must be >= 31 for any month
        addCat( "Lochi", FEMALE, SHORTHAIR, false, 12.4, GREEN, YELLOW, 112, "April 31, 2022") ;//A 30-day month can't have more than 30 days
        addCat( "Kochi", FEMALE, SHORTHAIR, false, 12.4, BLUE, GREEN, 113, "Feb 29, 2022") ;//February must have less than 29 days when it's not a leap year
        addCat( "Bob", FEMALE, SHORTHAIR, false, 12.4, ORANGE, AQUA, 114, "Feb 29, 2024") ;//February must have less than 30 days when it's a leap year. This shouldn't error!
        addCat( "Bobby", FEMALE, SHORTHAIR, false, 12.4, ORANGE, BLUE, 115, "Jeb 29, 2024") ;//Jeb is not a valid month

        //-------------------------------------------Check reportCats ------------------------------------------------
        printf("\n----reportCats checking----\n");
        printCat(0);// Prints Loki
        printCat(3); //Print Kali
        printf("Index of Cat Chili: %d\n",findCat("Chili"));//Prints 5
        printf("Index of Cat Bella: %d\n",findCat("Bella"));//Prints 2
        printf("-All the Cats in the database\n");
        printAllCats();
        //purposeful error checking
        printf("-There should be 1 error below :\n");
        findCat("hemrid");//Errors because cat is not in db

        //----------------------------------------Check updateCat-----------------------------------------------------
        printf("\n----updateCats checking----\n");
        //Next two lines do purposeful error checking
        int kali = findCat( "Kali" ) ;
        updateCatName( kali, "Chili" ) ; // this should fail because Chili is already in db
        updateBirthday( kali, "Jan 21, 2021");
        updateBirthday( kali, "Feb 29, 2021");
        printCat( kali );
        updateCatName( kali, "Capulet" ) ;
        updateCatWeight( kali, 9.9 ) ;
        fixCat( kali ) ;
        printCat( kali );
        updateCatCollar1( kali, BLUE );
        updateCatCollar2( kali, AQUA );
        updateLicense( kali, 4815162342 );
        printCat( kali );

        //--------------------------------------deleteCats-----------------------------------------------------------
        printf("\n----deleteCats checking----\n");
        printAllCats();
        deleteCat(3);
        printf("-Should have removed the 3rd cat in the array\n");
        printAllCats();//Should have removed cat #2 in the array list
        deleteAllCats();
        printf("-There should be nothing directly below this:\n");
        printAllCats();
        printf("\n");
    }//End of debug code

    if(EXTENSIVEDEBUG){
        /*
        //Provided main program testing
            #define MAX_NAME1 "1234567890123456789012345678901234567890123456789"
            #define MAX_NAME2 "DIFFERENT 123456789012345678901234567890123456789"
            #define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"

            printf( "Starting %s\n", PROGRAM_NAME ) ;
            initializeDatabase() ;
            addCat( "Loki", MALE, PERSIAN, true, 8.5, BLACK, WHITE, 101 ) ;
            addCat( "Milo", MALE, MANX, true, 7.0, BLACK, RED, 102 ) ;
            addCat( "Bella", FEMALE, MAINE_COON, true, 18.2, BLACK, BLUE, 103 ) ;
            addCat( "Kali", FEMALE, SHORTHAIR, false, 9.2, BLACK, GREEN, 104 ) ;
            addCat( "Trin", FEMALE, MANX, true, 12.2, BLACK, PINK, 105 ) ;
            addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106 ) ;
            //#ifdef DEBUG
            // Test for empty name
            assert( addCat( "", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, BLACK, WHITE, 101 ) == -1 ) ;
            // Test for max name
            assert( addCat( MAX_NAME1, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, RED, 107 ) != -1 ) ;
            // Test for name too long
            assert( addCat( ILLEGAL_NAME, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLUE, 108 ) == -1 ) ;
            // Test for duplicate cat name
            assert( addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, GREEN, 109 ) == -1 ) ;
            // Test for weight <= 0
            assert( addCat( "Neo", UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, PINK, 110 ) == -1 ) ;
            // Test for printCat( -1 ) ;
            printCat( -1 ) ;
            // Test for out of bounds
            printCat( 2000 ) ;
            // Test finding a cat...
            assert( findCat( "Bella" ) == 2 ) ;
            // Test not finding a cat
            assert( findCat( "Bella's not here" ) == -1 ) ;
            // Test addCat details

            //#endif
            printAllCats() ;
            int kali = findCat( "Kali" ) ;
            assert( updateCatName( kali, "Chili" ) == -1 ) ; // duplicate cat name should fail
            printCat( kali ) ;
            assert( updateCatName( kali, "Capulet" ) == 0 ) ;
            assert( updateCatWeight( kali, 9.9 ) == 0 ) ;
            assert( fixCat( kali ) == 0 ) ;
            assert( updateCatCollar1( kali, GREEN ) == 0 ) ;
            assert( updateCatCollar2( kali, GREEN ) == 0 ) ;
            assert( updateLicense( kali, 201 ) == 0 ) ;
            printCat( kali ) ;
            printAllCats() ;
            deleteAllCats() ;
            printAllCats() ;
            printf( "Done with %s\n", PROGRAM_NAME ) ;
            return( EXIT_SUCCESS ) ;
            */
    }//End of extensive Debug
}//End of main()
