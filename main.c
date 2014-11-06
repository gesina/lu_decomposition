

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
  int* pi;     // permutation vector
  
  if( dimension > 0 )
    {
      A_init =  init_matrix(dimension);
      if (!A_init) {return 2;}    // error with allociation?
      set_matrix(A_init, dimension);     // get actual input
  
      A = init_matrix(dimension);
      if (!A) {return 2;}    // error with allociation?
      copy_matrix(A_init, A, dimension); // copy A_init into workspace

      b = init_vector(dimension);        // equation system: Ax=b
      if (!b) {return 2;}    // error with allociation?
      set_vector(b, dimension);
      
      pi= (int*) malloc(dimension*sizeof(int));
      if ( pi == NULL )   // error with allociation?
	{
	  printf("Error allociating space in memory for the vector!\n");
	  printf("Problem occured with init of vector.");
	  return 2;
	}
    }
  else { printf("Dimension error, dimension is %d", dimension); return 3;} 

  
  // actual LU decompositon (b changed alongside)
  if(!lu_decomposition(A, b, pi, dimension)) {return 1;}; // check also, whether
                                                          // matrix is singular

  printf("\n\nRESULT of LU DECOMPOSITION:\n");
  printf("************************************************************\n");
  printf("\n Matrix P*A: \n");
  print_matrix(A_init, dimension);
  printf("\n Decomposed matrix:\n");
  print_matrix(A, dimension);             // print results
  printf("\n Vector pi: \n");
  // print pi
  for(int i=0; i<dimension; i++)
    {
      printf("   %d \n", *(pi+i));
    }

  // actual solving of Ax=b
  double* x= init_vector(dimension);
  solve_equation(A, b, x, dimension);      // A now R, b now z

  printf("\n\nSOLUTION of LINEAR EQUATION SYSTEM Ax=b:\n");
  printf("***********************************************************\n");
  printf("\n VECTOR x: \n");
  print_vector(x, dimension);            // print results

  
  
  // last but not least: 
  free_memory_matrix(A, dimension);
  free_memory_matrix(A_init, dimension);
  free_memory_vector(b);
  free_memory_vector(pi);
  free_memory_vector(x);
    
  print_exit(); // Bye, bye

}
