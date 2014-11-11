

/* ************************************************ */
/*                                                  */
/*   FILE: includes.h                               */
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
//  Summary of all included files
//    and all needed predefinitions
//
//---------------------------------------------------



// extern libraries
#include<stdlib.h>     // malloc & free for matrix/vector init
#include<stdio.h>      // printf(), scanf()
#include<math.h>       // fabs()


// VARIABLES
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

// dimension
static int dimension = -1; // -1: to test, whether get_dimension() worked



// PRINT-FUNCTIONS
void print_init(); // greetings
void print_exit(); // bye bye

void print_matrix(double** A, int dim);
void print_vector(double* b, int dim);


// ERRORS
void err_not_executable(int step_index); //prints index of last step
					 //and warning, in case no
                                         //LU decomposition is possible


// GET-FUNCTIONS
int get_dimension(); // gets matrix- and vector-dimension from user (n)
void set_matrix(double** A, int dim); // gets+sets matrix entries from user (A)
void set_vector(double* b, int dim); // gets+sets vector entries from user (b)


// INIT-FUNCTIONS
double** init_matrix(int dim); // allocates memory for matrix

double* init_vector(int dim); // allocates memory for vector

void free_memory_matrix(double** A, int dim);  // free memory from matrix
void free_memory_vector(void* x);   // free memory from vector

void copy_matrix(double** A,double** B,int dim); // copy matrix A into B


// LU DECOMPOSITION
struct LU_pi_step LU_decomposition(double** A, int dim);


// SUBSTITUTIONS: actual solving of Ax=b
void forward_substitution(double* b, int* pi, double** L, int dim);   // b~>z
void backward_substitution(double** U, double* z, double* x, int dim);// solve Ux=z








// HOMEMADE LIBRARIES
#include "print.h"              // print & error functions
#include "input.h"              // init, free & copy functions 
#include "lu_decomposition.h"   // LU_decomposition
#include "substitutions.h"      // forward & backward substitution



// ERROR CODES:
//  3: dimension error, dimension after user input lower 0
//  2: allociation error, malloc() didn't work
//  1: matrix not decomposable
//  0: exited normally
