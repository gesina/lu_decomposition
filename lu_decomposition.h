

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



_Bool lu_decomposition(double** A, double* b, int* pi, int dim)
{
  // write pi
  for (int i=0; i<dim; i++){ *(pi+i) = i;}

  double max_entry=0, next_entry=0;
  int temp_pi=0;
  double* temp_a=0;
  double temp_b=0;
  
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

      temp_b= b[k];                          // in b
      b[k]=b[pos_max_entry];
      b[pos_max_entry]=temp_b;

      

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
      printf("\n Vector b:\n");
      print_vector(b, dim);


      // LU Decomposition
      //---------------------------------
      // check on singularity:
      if ( max_entry == 0 )
	{
	  err_not_executable(k+1);
	  return 0;
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

	  // b
	  // b_{i} = b_{i} - l_{ik}*b_{k}
	  *(b+i) = *(b+i) - ( (*(*(A+i)+k)) * (*(b+k)) );

	}

      // print step
      printf("\n New Matrix:\n");
      print_matrix(A, dim);
      printf("\n New Vector b:\n");
      print_vector(b, dim);
      
    }

  return 1; // finished and worked well
}
