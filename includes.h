

/* ************************************************ */
/*                                                  */
/*   FILE: includes.h                               */
/*                                                  */
/*   PROJEKT:                                       */
/*   *************                                  */
/*    LR-ZERLEGUNG MIT SPALTENPIVOTSUCHE            */
/*       und Lösen eines linearen GLS               */
/*                                                  */
/*   im Rahmen der Numerikvorlesung im WS14/15      */
/*   von Prof. Dr. Blank an der Uni Regensburg      */
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
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<float.h>




// PRINT-FUNCTIONS
void print_init(); // greetings +  instructions
void print_exit(); // bye bye

void print_matrix(double** A, int dim);
void print_vector(double* b, int dim);

//void print_L(double** A, int dim);
//void print_R(double** A, int dim);


// GET-FUNCTIONS
int get_dimension(); // gets+sets matrix- and vector-dimensions from user (n,m)
void set_matrix(double** A, int dim); // gets+sets matrix entries from user (A)
void set_vector(double* b, int dim); // gets+sets vector entries from user (b)


// ERRORS
void err_not_executable(int step_index); //prints index of last step
					 //and warning, in case no
                                         //LU decomposition is possible


// INIT-FUNCTIONS
double** init_matrix(int dim); // allocates memory for matrix

double* init_vector(int dim); // allocates memory for vector

void free_memory_matrix(double** A, int dim);  // free memory from matrix
void free_memory_vector(void* x);   // free memory from vector

void copy_matrix(double** A,double** B,int dim); // copy matrix A into B

// actual LU decomposition algorithm
_Bool lu_decomposition(double** A, double* b, int* pi, int dim);

// actual solving of Ax=b
void solve_equation(double** R, double* z, double* x, int dim);



// intern libraries
#include "print.h"
#include "input.h"
#include "lu_decomposition.h"
#include "solve_equation.h"

