

/* ************************************************ */
/*                                                  */
/*   FILE: input.h                                  */
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
//   All input functions
//    and memory allocation
//
//---------------------------------------------------


// GET-FUNCTIONS
// gets+sets matrix- and vector-dimensions from user (n,m)
void set_dimension()
{

  int dim = -1; // dimension to return
  bool b=0;     // test bool for while-loop
  
  do  // as long as input doesn't make sense: repeat
    {
      b=0; // stop if not set to 1

      scanf("%i", &dim); // user read in

      // verify input
      if ( dim <= 0 )
	{
	  b=1;   // repeat if senseless
	  printf("Please enter a dimension greater than zero!");
	  printf("Your input: %i", dim);
	  printf("Try again."); // and give some warning
	};

    }
  while(b);

  // now input should be OK:
  return dim;
}


void set_matrix(double** A, int dim); // gets+sets matrix entries from user (A)
void set_vector(double* b, int dim); // gets+sets vector entries from user (b)



// MEMORY MANAGEMENT
// allocation functions
double** init_matrix(int dim)
{
  // allocate space for matrix row-pointer
  double** matrix = (double**) malloc(dim*sizeof(double*));
  
  // got space in memory?
  if ( matrix == NULL )
    {
      printf("Error allociating space in memory for the matrix!");
      printf("Problem occured with init of A");
      return -1; // exit
    }

  // allocate space for matrix rows 
  for ( int i=0; i<dim; i++)
    {
      // and for entries in rows
      matrix[i] = (double*) malloc(dim*sizeof(double));

      // got space in memory?
      if(matrix[i] == NULL)
	{
	  printf("Error allociating space in memory for the matrix!");
	  printf("Problem occured with row: A[%d]", i);
	  return -1; // exit
	}
    }

  return matrix;
  
};


double* init_vector(int dim) // allocates memory for vector
{
  // allocate space for matrix row-pointer
  double* vector = (double*) malloc(dim*sizeof(double));
  
  // got space in memory?
  if ( vector == NULL )
    {
      printf("Error allociating space in memory for the vector!");
      printf("Problem occured with init of vector.");
      return -1; // exit
    }

  return vector;
  
};

// memory free functions
// free memory from matrix
void free_memory_matrix(double** A, int dim)
{
  // free rows
  for (int i=0; i<dim; i++)
    {
      free(A[i]);
    }
  free(A);
}

// free memory from vector
void free_memory_vector(double* x)
{
    free(x);
}


// matrix copy
void copy_matrix(double** A,double** B,int dim); // copy matrix A into B

