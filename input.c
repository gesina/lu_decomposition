
/* ************************************************ */
/*                                                  */
/*   FILE: input.c                                  */
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

#include <stdio.h> // printf(), scanf()
#include <stdlib.h> // malloc(), free()

#include "input.h"
#include "print.h"


// GET-FUNCTIONS

char get_yesno()  // ask user for input of yes or no
{
  _Bool b=1;
  char c=' ';
  printf("\n Please enter yes (y) or no (n):  ");
   do
    {
      while(getchar()!='\n');  // necessary to avoid reading newline
      scanf("%c", &c);                             // get user input
      if ( c=='y' || c=='n' ) {b=0;}              // ok --> quit
      else { printf("\nPlease enter y or n :  "); }     // not ok --> repeat
    }
  while(b);

  return c; // return y or n
    
}



int get_dimension()  // gets matrix- and vector-dimensions from user (=n)
{

  int dim = -1; // dimension to return
  _Bool b=0;     // test bool for while-loop

  printf("\nPlease enter the dimension:  ");
  do  // as long as input doesn't make sense: repeat
    {
      b=0; // stop if not set to 1

      //      while(getchar()!='\n');  // necessary to avoid reading newline
      scanf("%d", &dim); // user read in

      // verify input
      if ( dim <= 0 )
	{
	  b=1;   // repeat if senseless
	  printf("\n  Please enter a dimension greater than zero!");
	  printf("\n  Your input: %i", dim);
	  printf("\nTry again:  "); // and give some warning
	};

    }
  while(b);

  return dim;

}

 
void set_matrix(double** A, int dim) // gets+sets matrix entries from user (A)
{
  
  _Bool b=0;     // test bool for while-loop
  char c=' ';     // helper character

  printf("Dimension for set_matrix: %d\n" , dim);
  printf("Please enter the matrix entries separately.");
  do  // as long as input doesn't make sense: repeat
    {
      b=1; // stop default
      
      for (int i=0; i<dim; i++)
	{
	  printf("\n Enter row #%i:\n", i+1);

	  // read entries in
	  for ( int j=0; j<dim; j++)
	    {
	      while(getchar()!='\n');  // necessary to avoid reading newline
	      scanf("%lf", (*(A+i)+j)); // user read in
	    }
	  
	  // show full row:
	  printf("Row #%d: ", i+1);
	  for (int k=0; k<dim; k++)
	    {
	      printf(" | %f", *(*(A+i)+k));
	    }
	}

      // ask, wether to continue or to try again  
      printf("\nYour entries have produced this matrix:\n");
      print_matrix(A, dim);
      printf("Take these entries?");
      
      c = get_yesno();
      if ( c=='y' ) { b=0;}
      else {printf("\nTry again and enter the first row:\n");}
      
    }
  while(b);

}

void set_vector(double* b, int dim) // gets+sets vector entries from user (b)
{
  
  _Bool g=0;     // test bool for while-loop
  char c=' ';     // helper character

  printf("\n\nPlease enter the entries of the vector: \n");
  do  // as long as input doesn't make sense: repeat
    {
      
      g=1; // stop default
      
      // read entries in
      for ( int i=0; i<dim; i++)
	{
	  while(getchar()!='\n');  // necessary to avoid reading newline
	  scanf("%lf", (b+i)); // user read in
	}
	 
      // ask, wether to continue or to try again  
      printf("\nYour entries have produced this vector:\n");
      print_vector(b, dim);
      printf("Take these entries and proceed with LU Decomposition?");
      
      c = get_yesno();
      if ( c=='y' ) { g=0;}
      else {printf("\n Try again and enter the vector:\n");}
      
    }
  while(g);

}



// MEMORY MANAGEMENT

// allocation functions
double** init_matrix(int dim)
{
  // allocate space for matrix row-pointer
  double** matrix = (double**) malloc(dim*sizeof(double*));
  
  // got space in memory?
  if ( matrix == NULL )
    {
      printf("Error allociating space in memory for the matrix!\n");
      printf("Problem occured with init of A");
      return NULL; // exit
    }

  // allocate space for matrix rows 
  for ( int i=0; i<dim; i++)
    {
      // and for entries in rows
      matrix[i] = (double*) malloc(dim*sizeof(double));

      // got space in memory?
      if(matrix[i] == NULL)
	{
	  printf("Error allociating space in memory for the matrix!\n");
	  printf("Problem occured with row: A[%d]", i);
	  return NULL; // exit
	}
    }

  return matrix;
  
};


double* init_vector(int dim) // allocates memory for vector
{
  // allocate space for vector
  double* vector = (double*) malloc(dim*sizeof(double));
  
  // got space in memory?
  if ( vector == NULL )
    {
      printf("Error allociating space in memory for the vector!\n");
      printf("Problem occured with init of vector.");
      return NULL; // exit
    }

  return vector;
  
};



// memory free functions
void free_memory_matrix(double** A, int dim)     // free memory from matrix
{
  // free rows
  for (int i=0; i<dim; i++)
    {
      free(A[i]);
    }
  free(A);
}


void free_memory_vector(void* x)                 // free memory from vector
{
    free(x);
}



// copy function
void copy_matrix(double** A, double** B,int dim) // copy matrix A into B
{
  // rows
  for (int i=0; i<dim; i++)
    {
      //columns
      for ( int j=0; j<dim; j++)
	{
	  *(*(B+i)+j) = *(*(A+i)+j);
	}
    };
}
