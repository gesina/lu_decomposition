

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
  dimension = get_dimension(); // ask dimension from user

  // init and get all variables
  double** A_init;
  double** A;     
  double* b;      
  double* pi;     
  if( dimension > 0 )
    {
      A_init =  init_matrix(dimension);
      if (!A_init) {return 2;}    // error with allociation?
      set_matrix(A_init, dimension);               // get actual input
  
      A = init_matrix(dimension);
      if (!A) {return 2;}    // error with allociation?
      copy_matrix(A_init, A, dimension);                   // copy A_init into workspace

      b = init_vector(dimension);        // equation system: Ax=b
      if (!b) {return 2;}    // error with allociation?
      set_vector(b, dimension);
      
      pi= init_vector(dimension);        // permutation vector
      if (!pi) {return 2;}    // error with allociation?
    }
  else { printf("Dimension error, dimension is %d", dimension); return 2;} 

  
  // actual LU decompositon (b changed alongside)
  //  lu_decomposition(A, b, pi, dimension);
  printf("\nresult: \n");
  print_matrix(A, dimension);             // print results
  printf("\n A_init: \n"); print_matrix(A_init, dimension);
  printf("\n Vector pi: \n");
  print_vector(pi, dimension);


  // actual solving of Ax=b
  double* x= init_vector(dimension);
  solve_equation(A, b, x, dimension);      // A now R, b now z

  print_vector(x, dimension);            // print results

  
  
  // last but not least: 
  free_memory_matrix(A, dimension);
  free_memory_matrix(A_init, dimension);
  free_memory_vector(b);
  free_memory_vector(pi);
  free_memory_vector(x);
    
  print_exit(); // Bye, bye

}
