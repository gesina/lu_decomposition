#ifndef INPUT
#define INPUT
/* ************************************************ */
/*                                                  */
/*   FILE: input.h                                  */
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
//   All input functions
//    and memory allocation
//
//---------------------------------------------------


// GET-FUNCTIONS

// ask user for input of yes or not
char get_yesno();

// gets matrix- and vector-dimensions from user (=n)
int get_dimension();

// gets+sets matrix entries from user (A)
void set_matrix(double** A, int dim);

// gets+sets vector entries from user (b)
void set_vector(double* b, int dim);



// MEMORY MANAGEMENT

//  ALLOCATION
// allocates memory for matrix
double** init_matrix(int dim);

// allocates memory for vector
double* init_vector(int dim);


//  MEMORY FREEING
// free memory from matrix
void free_memory_matrix(double** A, int dim);

// free memory from vector
void free_memory_vector(void* x);


//  COPY
// copy matrix A into B
void copy_matrix(double** A, double** B,int dim);


#endif
