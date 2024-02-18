# Task Description

The task is to implement a set of functions to handle sparse matrices. A sparse matrix is a matrix where there is set only a small fraction of its values. The remaining values are not set (and are usually considered zero). Since majority of the elements is not set, it makes sense to represent the matrix in a form more efficient than a 2D array. We will use linked lists in this homework.

The matrix itself is represented by structure TSPARSEMATRIX. The structure holds two pointer that point to the single linked lists with the description of the existing (non-empty) rows and columns; the rows and columns are described in structure TROWCOL. Both rows and columns are stored in an increasing row (column) index. Further, the TROWCOL structure contains a pointer m_Cells, this pointer points to the elements in the corresponding matrix row or column.

Structure TCELL describes a single element of the matrix. The structure holds the position (row and column), element value and two pointers: the next element in the same row and the next element in the same column. The elements in these lists are again stored in an ascending order (increasing value of column or row, respectively). The figure below depicts the structure with elements:

m[0, 1] = 10
m[1, 0] = 20
m[1, 5] = 30
m[2, 1] = 40

TSPARSEMATRIX
a data structure defined in the testing environment. Your implementation must use the structure, however, it must not modify it in any way. The structure represents a sparse matrix. The fields are:
m_Rows - pointer to the linked list that describes the existing matrix rows,
m_Cols - pointer to the linked list that describes the existing matrix columns.
TROWCOL
a data structure defined in the testing environment. Your implementation must use the structure, however, it must not modify it in any way. The structure is used to implement a linked list that describes the existing matrix rows and columns. The fields are:
m_Next - next row (column) of the matrix, nullptr for the last row (column),
m_Idx - row or column index,
m_Cells - a linked list of elements that form one row (column) of the matrix. Since linked list of TROWCOL only list existing rows (columns), the field m_Cells is never nullptr.
TCELL
a data structure defined in the testing environment. Your implementation must use the structure, however, it must not modify it in any way. The structure is used to implement one element of the matrix. The fields:
m_Right - pointer to the next element in the same row (with higher column index) or nullptr for the last element of the row,
m_Down - pointer to the next element in the same column (with higher row index) or nullptr for the last element of the column,
m_Row - row index,
m_Col - column index,
m_Data - the value of the element.
initMatrix ( m )
the function initializes an empty matrix - it sets both row and column pointers to nullptr.
addSetCell ( m, row, col, value )
the function adds n element to the matrix. The element is located at (row, col) and its value is set to value. If there already was an element at (row, col), then the function simply replaces the stored value. On the other hand, the function needs to create the element and connect it into the linked lists if the position (row, col) was not set yet.
removeCell ( m, row, col )
the function remove the matrix element at(row, col). If the element did not exist, the function returns false and leaves the matrix unchanged. If the element existed, the function removes the element and updates the affected linked lists. Caution, you may need to update the description of the existing rows/columns when removing the last defined element in a row/column.
freeMatrix ( m )
the function frees the memory allocated by the matrix.
Submit a source file with the implementation of the above functions. Further, the source file must include your auxiliary functions which are called from the required functions. Your functions will be called from the testing environment, thus, it is important to adhere to the required interface. Use the attached sample code as a basis for your development, complete the required functions and add your required auxiliary functions. There is an example main with some tests in the attached code. These test cases will be used in the basic test. Please note the header files as well as main is nested in a conditional compile block (#ifdef/#endif). Please keep these conditional compile block in place. They are present to simplify the development. When compiling on your computer, the headers and main will be present as usual. On the other hand, the header and main will "disappear" when compiled by Progtest. Thus, your testing main will not interfere with the testing environment's main.

Your function will be executed in a limited environment. There are limits on both time and memory. The exact limits are shown in the test log of the reference. A reasonable implementation of the naive algorithm shall pass both limits without any problems.