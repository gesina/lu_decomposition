#ifndef PRINT
#define PRINT
/* ************************************************ */
/*                                                  */
/*   FILE: print.h                                  */
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
//  All output functions
//
//---------------------------------------------------



// greetings +  instructions
void print_init();

// bye bye
void print_exit();

// matrix
void print_matrix(double** A, int dim);

// vector
void print_vector(double* b, int dim);

// prints index of last step
void err_not_executable(int step_index);


#endif
