#ifndef LU_DECOMP
#define LU_DECOMP
/* ************************************************ */
/*                                                  */
/*   FILE: lu_decomposition.h                       */
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
//  Actual LU decomposition function
//
//---------------------------------------------------


// machine epsilon
#define DBL_EPSILON 2.2204460492503131E-16


// LU decomposition of given Matrix A, returns completion indicator
int lu_decomposition(double** A, int* pi, int dim);

// return value of LU_decomposition():
struct LU_pi_step
{
  double** LU;       // LU decomposition of A
  int* pi;           // permutation vector pi
  int step;          // indicator:
                       // -1 if allociation of vector pi/matrix LU failed
                       //  0 if all worked well
                       // >0 if matrix cannot be decomposed (step it failed)
};


// prepares call of lu_decomposition
//   (init of LU, pi)
// and returns struct with LU, pi, step
struct LU_pi_step LU_decomposition(double** A, int dimension);


#endif
