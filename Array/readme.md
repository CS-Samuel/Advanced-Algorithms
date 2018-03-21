This program reads lines of integers from a file, removes duplicates, and
//  outputs a new line of integers without the duplicates.
//
//  This program begins by requesting the file name, opens the file and then
//  reads, processes and outputs each line to standard output. Data file must
//  be in the same folder as the program.
//
//  Each data set, or line, will contain a single array with the first value
//  giving the number of integers that follow.
//
//  The maximum number of integers for each line is 50 and the values are
//  between 0 and +100.
//
//  For each data set, the output of the array will be in the same order with
//  duplicate integers removed, one space between the integers and one blank
//  line between each data set output. The first occurence of any duplicated
//  integer is the one that remains in the array after removal.
//
//  Assignment requires a function that returns cleaned up array and its new
//  size: int* RemDups(int A[],int size, int newsize). Note: In order to
//  return newsize the function was modified to "int &newsize".
//
//  Assignment requires dynamic memory allocation for each array after
//  deleting the previous one.
