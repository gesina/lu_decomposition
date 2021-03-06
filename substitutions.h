#ifndef SUBSTITUTIONS
#define SUBSTITUTIONS
/* ************************************************ */
/*                                                  */
/*   FILE: substitutions.h                          */
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
//  Actual solving of the
//     linear equation system Ux=z
//
//---------------------------------------------------


// changes given vector b to z
void forward_substitution(double* b, int* pi, double** L, int dim);

// writes solution of Ux=z into given vector x
void backward_substitution(double** U, double* z, double* x, int dim);


#endif
