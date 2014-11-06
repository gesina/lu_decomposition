

/* ************************************************ */
/*                                                  */
/*   FILE: print.h                                  */
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
//  All output functions
//
//---------------------------------------------------



// greetings +  instructions
void print_init()
{
  printf("\nsome text that says what this is and what to do next\n");
};

// bye bye
void print_exit()
{
  printf("\nsome last words when all is done\n");
}

// matrix
void print_matrix(double** A, int dim)
{
  printf("\n print the information, e.g. the dimension: %d \n", dim);
  //rows
  for (int i=0; i<dim; i++)
    {
      //columns
      for(int j=0; j<dim; j++)
	{
	  printf("  %6.3f  ", *(*(A+i)+j)); // simple print: total 3 numbers, 1 after comma
	}
      printf("\n");  // begin new row
    }
}

// vector
void print_vector(double* b, int dim)
{
  for(int i=0; i<dim; i++)
    {
      printf("   %f \n", b[i]);
    }
}
  
void print_pivot_index(int i, int j);

//void print_L(double** A, int rows, int columns);
//void print_R(double** A, int rows, int columns);

