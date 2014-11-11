
/* ************************************************ */
/*                                                  */
/*   FILE: solve_equation.h                         */
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
//  Actual solving of the
//     linear equation system Ux=z
//
//---------------------------------------------------


// changes given vector b to z
void forward_substitution(double* b, int* pi, double** L, int dim)
{
  double temp_b=0; // for swaping of row entries

  // first swap all rows into new order
  for (int k=0; k<dim-1; k++)
    {
      // swap rows  b[k]<~>b[pi[k]]
      temp_b = b[k];
      b[k] = b[pi[k]];
      b[pi[k]] = temp_b;
    }

  // now calculate new entries iteratively
  for (int k=0; k<dim-1; k++)
    {
      // forward substitution
      for (int i=k+1; i<dim; i++)
	{
	  // b_{i} = b_{i} - l_{ik}*b_{k}
	  *(b+i) = *(b+i) - ( (*(*(L+i)+k)) * (*(b+k)) );
	}
    }


  // print result
  printf("\n Vector after forward substitution:\n");
  print_vector(b, dim);
  
}




// writes solution of Ux=z into given vector x
void backward_substitution(double** U, double* z, double* x, int dim)
{
  // go through the entries in x and set
  // x_{k} = [ z_{k}^{(k-1)} - ( \sum_{j=k+1}^{n} r_{kj}^{(k-1)}*x_{j} ) ]
  
  // for k=n, ..., 1
  for (int k=dim-1; k>=0; k--)
    {
      // x_{k} = z_{k}
      *(x+k) = *(z+k);

      // for j=k+1, ..., n
      for (int j=k+1; j<dim; j++)
	{
	  // x_{k} = x_{k}-r_{kj}x_{j}
	  *(x+k) = *(x+k) - (*(*(U+k)+j)) * (*(x+j));
	}

      // x_{k} = x_{k}/r_{kk}
      *(x+k) = (*(x+k)) /  (*(*(U+k)+k));
    }
}
