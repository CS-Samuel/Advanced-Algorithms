//***************************************************************************
//                                  Project #0
//                              Name:  Samuel Weems
//                           Course:  CMPS 3013, Fall 17
//                         Professor: Dr. Richard P. Simpson
//                              Date: September 06 2017
//***************************************************************************
//                                  Introduction
//
//  This program reads lines of integers from a file, removes duplicates, and
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
//***************************************************************************
//                              Program Complexity
//
// The complexity of this program is O(N) as it requires N comparisons.
// There is a fuller explanation under the function which performs most of the
// operations for this program.
//***************************************************************************
//
//  I have written the entire program as turned in and have not copied this
//  code, or parts of this code from the internet or another student.
//
//                                  Signature _______________________________
//
//***************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <math.h>

using namespace std;

// Function Declarations

int *RemDups(int A[], int size, int &newsize);

// Main Function

int main()
{

    string fileName;           // Name of file to be accessed
    ifstream inputFile;        // File Accessed
    bool fileAccessed = false; // Boolean to check for file accessibility

    int arraySize;    // Size of original array
    int newArraySize; // Size of adjusted array
    int *array;       // Pointer for original dynamic array
    int *newArray;    // Pointer for adjusted array

    // Request file name and check for access

    while (!fileAccessed)
    {
        cout << "Please type the name of the file (including extension) for processing and press <enter>:" << endl;
        cin >> fileName;

        if (fileName == "exit")
            return 0;

        inputFile.open(fileName);

        if (!inputFile.is_open())
            cout << endl
                 << "Error: Unable to access file! Make sure file is in program folder, check spelling, or type 'exit' to end program" << endl
                 << endl;
        else
            fileAccessed = true;
    }

    // Read array size, create dynamic array, and read array values

    while (inputFile >> arraySize)
    {
        array = new int[arraySize];
        for (int i = 0; i < arraySize; i++)
            inputFile >> array[i];

        // Call Function to make adjustments and remove duplicates

        newArray = RemDups(array, arraySize, newArraySize);

        // Output to screen results

        for (int i = 0; i < newArraySize; i++)
            cout << newArray[i] << " ";

        cout << endl;

        // Release dynamic memory

        delete[] newArray;
        delete[] array;
    }

    inputFile.close();

    return 0;
}

//***************************************************************************
//                       Main Program Function::RemDups()
//                  Paramaters: int A[], int size, int newsize
//                              Returns: int*
//                            Complexity: O(N)
//
// This function returns the cleaned up array and its new size.
//
// The function traverses the array. As it does this it sets a bit to indicate
// that integer has appeared and is a part of the set. If the integer has not
// appeared before in the array then the integer is added to a new array. There
// is a counter that keeps track of the size of the newly formed array.
//
// There are N comparisons made so the complexity is O(N). Each value of the
// array is tested to see if it has occured already.
//
// Ideally, using bits to keep track of the integers should be more space and
// time efficient depending on how bitset is implemented.
//
// Note: It would be more efficient to use a linked list or vectors but the
// assignment requires dynamic array structures. There is wasted space because
// the dynamic array created is the maxSize. This space loss could be traded
// for loss in time efficiency by creating the array after the initial
// loop through the original array once the correct size is known, marking the
// duplicates in the original array and copying the non-duplicates into the new
// array. If a linked list or vectors were used then there would be no loss of
// space since each new integer could be added and no loss of time since this
// could take place in the initial loop.
//***************************************************************************

int *RemDups(int A[], int size, int &newsize)
{
    const int maxValue = 100;
    const int maxSize = 50;
    int *tempArray;
    bitset<maxValue + 1> integerTracker;

    tempArray = new int[maxSize];
    newsize = 0;

    for (int i = 0; i < size; i++)
    {
        if (!(integerTracker.test(A[i])))
        {
            integerTracker.set(A[i]);
            tempArray[newsize] = A[i];
            ++newsize;
        }
    }
    return tempArray;
}
