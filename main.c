
/* ************************************************ */
/*                                                  */
/*   FILE: main.c                                   */
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


// include all needed libraries and predefinitions
#include <stdio.h>  // printf()
#include <stdlib.h> // malloc()

#include "main.h"
#include "input.h"
#include "print.h"
#include "lu_decomposition.h"
#include "substitutions.h"


// main function
int main(void)
{

  // greeting
  print_init();


  // get and set dimension
  dimension = get_dimension(); // ask dimension from user
  // last check for correct dimension:
  if( dimension <= 0 )
    {
      printf("Dimension error, dimension is %d", dimension);
      return 3; // dimension error
    }
  

  // init variables
  double** A;     



  // set A;
  A =  init_matrix(dimension);
  if (!A) {return 2;}    // error with allociation?
  set_matrix(A, dimension);     // get actual input from user
  
  
  
  // ACTUAL LU DECOMPOSITION
  //--------------------------------------------------
  
  struct LU_pi_step temp_struct = LU_decomposition(A, dimension);
  
  // check on allociation problems:
  if ( temp_struct.step == -1 ) {return 2;}
  // check also, whether matrix is singular:
  if ( temp_struct.step > 0 ) {return 1;}

  // if all worked well, print result
  printf("\n\nRESULT of LU DECOMPOSITION:\n");
  printf("************************************************************\n");
  printf("\n Matrix A: \n");
  print_matrix(A, dimension);              // print matrix from beginning
  printf("\n Decomposed matrix P*A=L*U:\n");
  print_matrix(temp_struct.LU, dimension);      // print results
  printf("\n Permutation vector pi: \n");
  // print pi
  for(int i=0; i<dimension; i++)
    {
      printf("   %d \n", *(temp_struct.pi+i));
    }


  
  
  // ACTUAL SOLVING of Ax=b
  //----------------------------------------------

  // init and set vector b
  double* b = init_vector(dimension);        // equation system: Ax=b
  if (!b) {return 2;}    // error with allociation?
  printf("\n***********************************************************\n");
  printf("***********************************************************\n");
  printf("\n\nNow a linear equation system Ax=b can be solved.");
  set_vector(b, dimension); // get entries from user

  // FORWARD SUBSTITUTION for b:
  // (means: write P*L*b = z into b
  forward_substitution(b, temp_struct.pi, temp_struct.LU, dimension);

   
  // init vector x
  double* x= init_vector(dimension);

  // BACKWARD SUBSTITUTION for x
  // (means: write solution of Ux=z or Ax=b into x)
  backward_substitution(temp_struct.LU, b, x, dimension);      // A now U, b now z

  printf("\n\nSOLUTION of LINEAR EQUATION SYSTEM Ax=b:\n");
  printf("***********************************************************\n");
  printf("\n VECTOR x: \n");
  print_vector(x, dimension);            // print results



  
  
  // last but not least:
  free_memory_matrix(A, dimension);
  free_memory_matrix(temp_struct.LU, dimension);
  free_memory_vector(b);
  free_memory_vector(temp_struct.pi);
  free_memory_vector(x);


  // Bye, bye
  print_exit();


  return 0;
}
