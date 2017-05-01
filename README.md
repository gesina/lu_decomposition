# Implementation of LU decomposition

This project was an excercise for the lecture 
*Numerical Mathematics* for Bachelor students by
[Prof. Dr. Blank](http://www.mathematik.uni-regensburg.de/Mat8/Blank/)
at the University of Regensburg in 2014. It implements the Doolittle
algorithm (in German "Spaltenpivotisierung") for
[LU decomposition (with partial pivoting)](https://en.wikipedia.org/wiki/LU_decomposition) 
of a given matrix and the solution of a linear equation system
herewith.

For a matrix *A* the algorithm yields a permutation of rows *P* (can be
written as vector) and a matrix *B*, s.t. taking
- *L* the part of *B* below the diagonal (the latter inclusive) and
- *U* the part of *B* above the diagonal (the latter inclusive)
then *PA=LU* and all entries of *L* have absolute value lower than 1.
See also the description in the 
[corresponding script of the lecture](https://github.com/gesina/numerik2014).


## Compilation
You will need __gcc__ and __make__. Then simply call
```bash
make
```

## Functionality
The output program `lu_decomposition` will, after calling it with

```bash
./lu_decomposition
```

- ask for the input of a dimension and a square matrix of this dimension
- print the single steps for __LU decomposition__ of this matrix
  (i.e. the permutation vector *P* and the state of *B*)
- ask for the input of a vector *b*
- print the single steps for the __solution of the linear equation
  system *Ax=b*__ with the LU decomposition from above

See also the comments in the source files.


## Structure of the Files
Mind the (quite elaborate) comments in the source files that try to
describe the functionality.

- LU decompositions: `lu_decomposition.*`
- Solution of linear equation systems: `substitutions.*` 
- Main function: `main.*`
- Input, memory allocation, output: `input.*`, `print.*`
