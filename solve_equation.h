

/* ************************************************ */
/*                                                  */
/*   FILE: solve_equation.h                         */
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
//  Actual solving of the
//     linear equation system Rx=z
//
//---------------------------------------------------



void solve_equation(double** R, double* z, double* x, int dim)
{
  // got through the entries in x and set
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
	  *(x+k) = *(x+k) - (*(*(R+k)+j)) * (*(x+j));
	}

      // x_{k} = x_{k}/r_{kk}
      *(x+k) = (*(x+k)) /  (*(*(R+k)+k));
      
    }
}
