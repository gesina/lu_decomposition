

/* ************************************************ */
/*                                                  */
/*   FILE: main.c                                   */
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
//  Main executive file with LU decomposition
//    and solving of linear equation system
//
//---------------------------------------------------


// include all needed libraries and other functions
#include "includes.h"


// "global" variables
static int dimension = -1;


// main function
int main(void)
{
  
  print_init(); // greeting + instructions


  // get and set all needed data
  set_dimensions(); // ask dimension from user

  // init and get all variables
  if( dimension > 0 ) {
    double** A_init =  init_matrix();
      if (A_init == -1) {return 2;}    // error with allociation?
    set_matrix(A_init, dimension);               // get actual input
  
    double** A = init_matrix(dimension);
      if (A == -1) {return 2;}    // error with allociation?
    copy_matrix(A, dimension);                   // copy A_init into workspace

    double* b = init_vector(dimension);        // equation system: Ax=b
      if (b == -1) {return 2;}    // error with allociation?
    
    double* pi= init_vector(dimension);        // permutation vector
      if (pi == -1) {return 2;}    // error with allociation?
  }
  else { printf("Dimension error, dimension is %i", dimension); return 2;} 

  
  // actual LU decompositon (b changed alongside)
  lu_decomposition(A, b, pi);
  print_matrix(A);             // print results
  print_vector(pi);


  // actual solving of Ax=b
  double* x= init_vector(dimension);
  solve_equation(A, b, x);      // A now R, b now z

  print_vector(x);            // print results

  
  
  // last but not least: 
  free_memory_matrix(A, dimension);
  free_memory_matrix(A_init, dimension);
  free_memory_vector(b);
  free_memory_vector(pi);
  free_memory_vector(x);
    
  print_exit(); // Bye, bye

}
