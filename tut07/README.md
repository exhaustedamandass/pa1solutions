# Task Description

The task is to implement a function (not a whole program, just a function) to cyclically rotate the contents of an array.

The required function interface is as follows:

void rotateArray ( int array[], int arrayLen, int rotateBy );
array is an input/output parameter that references the array to rotate,
arrayLen is the length of the array (the number of elements in the array),
rotateBy is the shift. A value of 0 means no change. A positive value means to shift the elements towards the end of the array, a negative value shifts array elements towards the beginning of the array. For example rotateBy=2 means to move array[0] to array[2], array[1] to array[3], …, array[arrayLength - 2] to array[0] and array[arrayLength-1] to array[1].
the function must be as efficient as possible. In particular, the function must not allocate any additional temporary array (there is some memory left for a few integer variables, however, there is not enough memory to duplicate the entire input array).
There are example function calls included in the attached archive.