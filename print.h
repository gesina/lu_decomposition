

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
  printf("some text that says what this is and what to do next");
};

// bye bye
void print_exit()
{
  printf("some last words when all is done");
}

void print_matrix(double** A, int dim)
{
  printf("print the information, e.g. 'the dimension is %d '", dim);
}
void print_vector(double* b, int dim);
void print_pivot_index(int i, int j);

//void print_L(double** A, int rows, int columns);
//void print_R(double** A, int rows, int columns);

