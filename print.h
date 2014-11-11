

/* ************************************************ */
/*                                                  */
/*   FILE: print.h                                  */
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
//  All output functions
//
//---------------------------------------------------



// greetings +  instructions
void print_init()
{
  printf("\n****************************************************");
  printf("\n*                                                  *");
  printf("\n*    LU-DECOMPOSITION WITH PIVOTING                *");
  printf("\n*                 and                              *");
  printf("\n*    SOLVING OF A LINEAR EQUATION SYSTEM           *");
  printf("\n*                                                  *");
  printf("\n****************************************************\n");
};

// bye bye
void print_exit()
{
  printf("\nThanks for using this little programm.\n");
  printf("\n      Yours");
  printf("\n             Kerstin Blomenhofer");
  printf("\n             Gesina Schwalbe\n\n");
}

// matrix
void print_matrix(double** A, int dim)
{
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
      printf("   %f \n", *(b+i));
    }
}


// prints index of last step
void err_not_executable(int step_index)
{
  printf("\n\nSorry, the matrix cannot be pivoted!\n");
  printf("Failed step:  %d\n", step_index);
}

//void print_L(double** A, int rows, int columns);
//void print_R(double** A, int rows, int columns);

