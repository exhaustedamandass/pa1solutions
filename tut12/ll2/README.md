# Task Description

Your task is to implement č functions that handle a double-linked list. The required functions are:

Function insertStart ( l, x ) adds a new element with value x to the beginning of list l.
Function insertEnd ( l, x ) adds a new element with value x to the end of list l.
Function removeMax ( l ) finds the maximum value in the list. Then the function removes all elements with value equal to the maximum value. Return value is the number of elements removed from the list (the value may be greater than zero if the maximum is present more than once; it may be even 0 if the list is empty).
Function destroyAll ( l ) frees the memory used by all elements in the list l.
Structure TDATA represents a linked list. The fields are m_First (a pointer to the first element in the list) and m_Last (a pointer to the last element in the list). Structure TDATA is declared in the testing environment, your implementation cannot change it in any way. An empty linked list is represented as a structure with both fields set to NULL.
Structure TITEM represents one element in the linked list. The fields are m_Next (a pointer to the next element in the list, NULL for the last element in the list), m_Prev (a pointer to the previous element in the list, NULL for the first element), and field m_Val (the integer to save).
The attached archive contains a source code with function declarations and sample tests. Use the attached source as a basis for your implementation. Please preserve the conditional compile blocks (#ifndef / #endif). If present, the source may be both tested locally and submitted to the Progtest. Pay special attention to the memory operations and pointers in general. Use memory debugger to test your implementation before you submit your program to Progtest.

This problem is 0.1 pts maximum. Solve & submit both problems to get all points.