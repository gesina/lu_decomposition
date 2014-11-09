

/* ************************************************ */
/*                                                  */
/*   FILE: lu_decomposition.h                       */
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
//  Actual LU decomposition function
//
//---------------------------------------------------


int lu_decomposition(double** A, int* pi, int dim)
{
  // write pi
  //for (int i=0; i<dim; i++){ *(pi+i) = i;}

  double max_entry=0, next_entry=0;
  int temp_pi=0;
  double* temp_a=0;
  
  for (int k=0; k<dim-1; k++)
    {
      // Pivoting
      //---------------------------------
      // find maximum absolute value of entries
      max_entry= fabs(*(*(A+k)+k));      // set max to abs. value
                                         // of entry #k in row #k
      int pos_max_entry=k;
      
      for (int i=k+1; i<dim; i++)
	{
	  next_entry=fabs(*(*(A+i)+k));  // get next abs. entry
	  
	  if(max_entry < next_entry)     // and if greater ...
	    {
	      max_entry = next_entry;    // ... take it as max
	      pos_max_entry = i;
	    }
	}
      //printf("\nmax_entry: %f,   pos_max_entry: %d", max_entry, pos_max_entry);

      // swap rows
      temp_pi = pi[k];                       // in pi
      pi[k]=pi[pos_max_entry];
      pi[pos_max_entry]=temp_pi; 

      temp_a = *(A+k);                       // in A
      *(A+k)=*(A+pos_max_entry);
      *(A+pos_max_entry)=temp_a;

      /* temp_b= b[k];                          // in b */
      /* b[k]=b[pos_max_entry]; */
      /* b[pos_max_entry]=temp_b; */

      

      // print step
      printf("\n\n STEP %d\n", k+1);
      printf("*******************");
      // prints Pivot index
      printf("\nCurrent Pivot index:  A[%d][%d] = %f", pos_max_entry, k, (*(*A+k)+k));
      printf("\n Matrix:\n");
      print_matrix(A, dim);
      printf("\n Permutation vector:\n");
      // print pi
      for(int i=0; i<dim; i++)
	{
	  printf("   %d \n", *(pi+i));
	}
      /* printf("\n Vector b:\n"); */
      /* print_vector(b, dim); */


      // LU Decomposition
      //---------------------------------
      // check on singularity:
      if ( max_entry == 0 )
	{
	  err_not_executable(k+1);
	  return k+1;
	}

      // change entries
      for (int i=k+1; i<dim; i++)
	{
	  // L
	  // l_{ik} = a_{ik}/a_{kk}
	  *(*(A+i)+k) = (*(*(A+i)+k))/ (*(*(A+k)+k));
	  for (int j=k+1; j<dim; j++)
	    {
	      // R
	      // a_{ij} = a_{ij} - l_{ik}*a_{ki}
	      *(*(A+i)+j) = *(*(A+i)+j) - ( (*(*(A+i)+k)) * (*(*(A+k)+j)) );
	    }

	  /* // b */
	  /* // b_{i} = b_{i} - l_{ik}*b_{k} */
	  /* *(b+i) = *(b+i) - ( (*(*(A+i)+k)) * (*(b+k)) ); */

	}

      // print step
      printf("\n New Matrix:\n");
      print_matrix(A, dim);
      /* printf("\n New Vector b:\n"); */
      /* print_vector(b, dim); */
      
    }

    

  return 0; // finished and worked well
}







struct LU_pi_step LU_decomposition(double** A, int dimension)
{
  // init of struct to return with
  // default value for allociation error
  struct LU_pi_step return_struct = {NULL, NULL, -1};
  
  // init of permutation vector pi
  return_struct.pi= (int*) malloc(dimension*sizeof(int));
  if ( return_struct.pi == NULL )   // error with allociation?
    {
      printf("Error allociating space in memory for the vector!\n");
      printf("Problem occured with init of permutation vector.");
      return return_struct;
    };
  
  // write entries of permutation vector
  for (int i=0; i<dimension; i++){ *(return_struct.pi+i) = i;}


  // init of LU matrix
  return_struct.LU = init_matrix(dimension);
  if (!return_struct.LU) {return return_struct;}    // error with allociation?
  
  // set return_struct.LU to A:
  copy_matrix(A, return_struct.LU, dimension);

  
  // decompose A to LR and set step
  // (step=0: worked well; step>0: failed
  return_struct.step = lu_decomposition(return_struct.LU, return_struct.pi, dimension);

  return return_struct;
  
}
  


