#ifndef MAIN
#define MAIN
/* ************************************************ */
/*                                                  */
/*   FILE: main.h                                   */
/*                                                  */
/*   PROJECT:                                       */
/*   *************                                  */
/*    LU-DECOMPOSITION WITH PIVOTING                */
/*      and                                         */
/*    SOLVING OF A LINEAR EQUATION SYSTEM           */
/*                                                  */
/*   Excercise #20 for the lecture                  */
/*   NUMERICAL MATHEMATICS in 2014/15               */
/*   by Prof. Dr. Blank                             */
/*   University of Regensburg                       */
/*                                                  */
/*   AUTHORS:                                       */
/*   *************                                  */
/*     Kerstin Blomenhofer and Gesina Schwalbe      */
/*     Group 30                                     */
/*                                                  */
/* ************************************************ */


//---------------------------------------------------
//
//  Main executive file for LU decomposition
//    and solving of linear equation system
//
//---------------------------------------------------


// VARIABLES
// dimension
static int dimension = -1; // -1: to test, whether get_dimension() worked

// MAIN function
int main(void);
// ERROR CODES:
//  3: dimension error, dimension after user input lower 0
//  2: allociation error, malloc() didn't work
//  1: matrix not decomposable
//  0: exited normally

#endif
