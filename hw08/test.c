#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct TCell
{
  struct TCell             * m_Right;
  struct TCell             * m_Down;
  int                        m_Row;
  int                        m_Col;
  int                        m_Data;
} TCELL;

typedef struct TRowCol
{
  struct TRowCol           * m_Next;
  TCELL                    * m_Cells;
  int                        m_Idx;
} TROWCOL;

typedef struct TSparseMatrix
{
  TROWCOL                  * m_Rows;
  TROWCOL                  * m_Cols;
} TSPARSEMATRIX;
#endif /* __PROGTEST__ */

void initMatrix   ( TSPARSEMATRIX   * m )
{
    m->m_Rows = nullptr;
    m->m_Cols = nullptr;
}
void addSetCell   ( TSPARSEMATRIX   * m,
                    int               rowIdx,
                    int               colIdx,
                    int               data )
{
    TROWCOL* rowPtr = m->m_Rows;
    TROWCOL* prevRow = nullptr;
    while (rowPtr != nullptr && rowPtr->m_Idx < rowIdx) {
        prevRow = rowPtr;
        rowPtr = rowPtr->m_Next;
    }
    if (rowPtr == nullptr || rowPtr->m_Idx != rowIdx) {
        TROWCOL* newRow = (TROWCOL*)malloc(sizeof(TROWCOL));
        newRow->m_Next = rowPtr;
        newRow->m_Idx = rowIdx;
        newRow->m_Cells = nullptr;
        if (prevRow == nullptr) {
            m->m_Rows = newRow;
        } else {
            prevRow->m_Next = newRow;
        }
        rowPtr = newRow;
    }

    TROWCOL* colPtr = m->m_Cols;
    TROWCOL* prevCol = nullptr;
    while (colPtr != nullptr && colPtr->m_Idx < colIdx) {
        prevCol = colPtr;
        colPtr = colPtr->m_Next;
    }
    if (colPtr == nullptr || colPtr->m_Idx != colIdx) {
        TROWCOL* newCol = (TROWCOL*)malloc(sizeof(TROWCOL));
        newCol->m_Next = colPtr;
        newCol->m_Idx = colIdx;
        newCol->m_Cells = nullptr;
        if (prevCol == nullptr) {
            m->m_Cols = newCol;
        } else {
            prevCol->m_Next = newCol;
        }
        colPtr = newCol;
    }

    TCELL* cellPtr = rowPtr->m_Cells;
    TCELL* prevCell = nullptr;
    while (cellPtr != nullptr && cellPtr->m_Col < colIdx) {
        prevCell = cellPtr;
        cellPtr = cellPtr->m_Right;
    }
    if (cellPtr == nullptr || cellPtr->m_Col != colIdx) {
        TCELL* newCell = (TCELL*)malloc(sizeof(TCELL));
        newCell->m_Row = rowIdx;
        newCell->m_Col = colIdx;
        newCell->m_Data = data;
        newCell->m_Right = cellPtr;
        newCell->m_Down = nullptr;
        if (prevCell == nullptr) {
            rowPtr->m_Cells = newCell;
        } else {
            prevCell->m_Right = newCell;
        }

        TCELL* colCellPtr = colPtr->m_Cells;
        TCELL* prevColCell = nullptr;
        while (colCellPtr != nullptr && colCellPtr->m_Row < rowIdx) {
            prevColCell = colCellPtr;
            colCellPtr = colCellPtr->m_Down;
        }
        newCell->m_Down = colCellPtr;
        if (prevColCell == nullptr) {
            colPtr->m_Cells = newCell;
        } else {
            prevColCell->m_Down = newCell;
        }
    } else {
        cellPtr->m_Data = data;
    }

}
bool removeCell   ( TSPARSEMATRIX   * m,
                    int               rowIdx,
                    int               colIdx )
{
        TROWCOL* rowPtr = m->m_Rows;
    TROWCOL* prevRow = nullptr;
    while (rowPtr != nullptr && rowPtr->m_Idx < rowIdx) {
        prevRow = rowPtr;
        rowPtr = rowPtr->m_Next;
    }
    if (rowPtr == nullptr || rowPtr->m_Idx != rowIdx) {
        return 0; 
    }

    TROWCOL* colPtr = m->m_Cols;
    TROWCOL* prevCol = nullptr;
    while (colPtr != nullptr && colPtr->m_Idx < colIdx) {
        prevCol = colPtr;
        colPtr = colPtr->m_Next;
    }
    if (colPtr == nullptr || colPtr->m_Idx != colIdx) {
        return 0; 
    }

    TCELL* cellPtr = rowPtr->m_Cells;
    TCELL* prevCell = nullptr;
    while (cellPtr != nullptr && cellPtr->m_Col < colIdx) {
        prevCell = cellPtr;
        cellPtr = cellPtr->m_Right;
    }
    if (cellPtr == nullptr || cellPtr->m_Col != colIdx) {
        return 0; 
    }

    if (prevCell == nullptr) {
        rowPtr->m_Cells = cellPtr->m_Right;
    } else {
        prevCell->m_Right = cellPtr->m_Right;
    }

    TCELL* colCellPtr = colPtr->m_Cells;
    TCELL* prevColCell = nullptr;
    while (colCellPtr != nullptr && colCellPtr->m_Row < rowIdx) {
        prevColCell = colCellPtr;
        colCellPtr = colCellPtr->m_Down;
    }
    if (prevColCell == nullptr) {
        colPtr->m_Cells = cellPtr->m_Down;
    } else {
        prevColCell->m_Down = cellPtr->m_Down;
    }

    free(cellPtr);

    if (rowPtr->m_Cells == nullptr) {
        if (prevRow == nullptr) {
            m->m_Rows = rowPtr->m_Next;
        } else {
            prevRow->m_Next = rowPtr->m_Next;
        }
        free(rowPtr);
    }

    if (colPtr->m_Cells == nullptr) {
        if (prevCol == nullptr) {
            m->m_Cols = colPtr->m_Next;
        } else {
            prevCol->m_Next = colPtr->m_Next;
        }
        free(colPtr);
    }

    return 1; 
}
void freeMatrix   ( TSPARSEMATRIX   * m )
{
        TROWCOL* rowPtr = m->m_Rows;
    while (rowPtr != nullptr) {
        TROWCOL* nextRow = rowPtr->m_Next;
        TCELL* cellPtr = rowPtr->m_Cells;
        while (cellPtr != nullptr) {
            TCELL* nextCell = cellPtr->m_Right;
            free(cellPtr);
            cellPtr = nextCell;
        }
        free(rowPtr);
        rowPtr = nextRow;
    }
    m->m_Rows = nullptr;

    TROWCOL* colPtr = m->m_Cols;
    while (colPtr != nullptr) {
        TROWCOL* nextCol = colPtr->m_Next;
        free(colPtr);
        colPtr = nextCol;
    }
    m->m_Cols = nullptr;
}
#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  TSPARSEMATRIX  m;
  initMatrix ( &m );
  addSetCell ( &m, 0, 1, 10 );
  addSetCell ( &m, 1, 0, 20 );
  addSetCell ( &m, 1, 5, 30 );
  addSetCell ( &m, 2, 1, 40 );
  assert ( m . m_Rows
           && m . m_Rows -> m_Idx == 0
           && m . m_Rows -> m_Cells
           && m . m_Rows -> m_Cells -> m_Row == 0
           && m . m_Rows -> m_Cells -> m_Col == 1
           && m . m_Rows -> m_Cells -> m_Data == 10
           && m . m_Rows -> m_Cells -> m_Right == nullptr );
  assert ( m . m_Rows -> m_Next
           && m . m_Rows -> m_Next -> m_Idx == 1
           && m . m_Rows -> m_Next -> m_Cells
           && m . m_Rows -> m_Next -> m_Cells -> m_Row == 1
           && m . m_Rows -> m_Next -> m_Cells -> m_Col == 0
           && m . m_Rows -> m_Next -> m_Cells -> m_Data == 20
           && m . m_Rows -> m_Next -> m_Cells -> m_Right
           && m . m_Rows -> m_Next -> m_Cells -> m_Right -> m_Row == 1
           && m . m_Rows -> m_Next -> m_Cells -> m_Right -> m_Col == 5
           && m . m_Rows -> m_Next -> m_Cells -> m_Right -> m_Data == 30
           && m . m_Rows -> m_Next -> m_Cells -> m_Right -> m_Right == nullptr );
  assert ( m . m_Rows -> m_Next -> m_Next
           && m . m_Rows -> m_Next -> m_Next -> m_Idx == 2
           && m . m_Rows -> m_Next -> m_Next -> m_Cells
           && m . m_Rows -> m_Next -> m_Next -> m_Cells -> m_Row == 2
           && m . m_Rows -> m_Next -> m_Next -> m_Cells -> m_Col == 1
           && m . m_Rows -> m_Next -> m_Next -> m_Cells -> m_Data == 40
           && m . m_Rows -> m_Next -> m_Next -> m_Cells -> m_Right == nullptr );
  assert ( m . m_Rows -> m_Next -> m_Next -> m_Next == nullptr );
  assert ( m . m_Cols
           && m . m_Cols -> m_Idx == 0
           && m . m_Cols -> m_Cells
           && m . m_Cols -> m_Cells -> m_Row == 1
           && m . m_Cols -> m_Cells -> m_Col == 0
           && m . m_Cols -> m_Cells -> m_Data == 20
           && m . m_Cols -> m_Cells -> m_Down == nullptr );
  assert ( m . m_Cols -> m_Next
           && m . m_Cols -> m_Next -> m_Idx == 1
           && m . m_Cols -> m_Next -> m_Cells
           && m . m_Cols -> m_Next -> m_Cells -> m_Row == 0
           && m . m_Cols -> m_Next -> m_Cells -> m_Col == 1
           && m . m_Cols -> m_Next -> m_Cells -> m_Data == 10
           && m . m_Cols -> m_Next -> m_Cells -> m_Down
           && m . m_Cols -> m_Next -> m_Cells -> m_Down -> m_Row == 2
           && m . m_Cols -> m_Next -> m_Cells -> m_Down -> m_Col == 1
           && m . m_Cols -> m_Next -> m_Cells -> m_Down -> m_Data == 40
           && m . m_Cols -> m_Next -> m_Cells -> m_Down -> m_Down == nullptr );
  assert ( m . m_Cols -> m_Next -> m_Next
           && m . m_Cols -> m_Next -> m_Next -> m_Idx == 5
           && m . m_Cols -> m_Next -> m_Next -> m_Cells
           && m . m_Cols -> m_Next -> m_Next -> m_Cells -> m_Row == 1
           && m . m_Cols -> m_Next -> m_Next -> m_Cells -> m_Col == 5
           && m . m_Cols -> m_Next -> m_Next -> m_Cells -> m_Data == 30
           && m . m_Cols -> m_Next -> m_Next -> m_Cells -> m_Down == nullptr );
  assert ( m . m_Cols -> m_Next -> m_Next -> m_Next == nullptr );
  assert ( m . m_Rows -> m_Cells == m . m_Cols -> m_Next -> m_Cells );
  assert ( m . m_Rows -> m_Next -> m_Cells == m . m_Cols -> m_Cells );
  assert ( m . m_Rows -> m_Next -> m_Cells -> m_Right == m . m_Cols -> m_Next -> m_Next -> m_Cells );
  assert ( m . m_Rows -> m_Next -> m_Next -> m_Cells == m . m_Cols -> m_Next -> m_Cells -> m_Down );
  addSetCell ( &m, 230, 190, 50 );
  assert ( m . m_Rows
           && m . m_Rows -> m_Idx == 0
           && m . m_Rows -> m_Cells
           && m . m_Rows -> m_Cells -> m_Row == 0
           && m . m_Rows -> m_Cells -> m_Col == 1
           && m . m_Rows -> m_Cells -> m_Data == 10
           && m . m_Rows -> m_Cells -> m_Right == nullptr );
  assert ( m . m_Rows -> m_Next
           && m . m_Rows -> m_Next -> m_Idx == 1
           && m . m_Rows -> m_Next -> m_Cells
           && m . m_Rows -> m_Next -> m_Cells -> m_Row == 1
           && m . m_Rows -> m_Next -> m_Cells -> m_Col == 0
           && m . m_Rows -> m_Next -> m_Cells -> m_Data == 20
           && m . m_Rows -> m_Next -> m_Cells -> m_Right
           && m . m_Rows -> m_Next -> m_Cells -> m_Right -> m_Row == 1
           && m . m_Rows -> m_Next -> m_Cells -> m_Right -> m_Col == 5
           && m . m_Rows -> m_Next -> m_Cells -> m_Right -> m_Data == 30
           && m . m_Rows -> m_Next -> m_Cells -> m_Right -> m_Right == nullptr );
  assert ( m . m_Rows -> m_Next -> m_Next
           && m . m_Rows -> m_Next -> m_Next -> m_Idx == 2
           && m . m_Rows -> m_Next -> m_Next -> m_Cells
           && m . m_Rows -> m_Next -> m_Next -> m_Cells -> m_Row == 2
           && m . m_Rows -> m_Next -> m_Next -> m_Cells -> m_Col == 1
           && m . m_Rows -> m_Next -> m_Next -> m_Cells -> m_Data == 40
           && m . m_Rows -> m_Next -> m_Next -> m_Cells -> m_Right == nullptr );
  assert ( m . m_Rows -> m_Next -> m_Next -> m_Next
           && m . m_Rows -> m_Next -> m_Next -> m_Next -> m_Idx == 230
           && m . m_Rows -> m_Next -> m_Next -> m_Next -> m_Cells
           && m . m_Rows -> m_Next -> m_Next -> m_Next -> m_Cells -> m_Row == 230
           && m . m_Rows -> m_Next -> m_Next -> m_Next -> m_Cells -> m_Col == 190
           && m . m_Rows -> m_Next -> m_Next -> m_Next -> m_Cells -> m_Data == 50
           && m . m_Rows -> m_Next -> m_Next -> m_Next -> m_Cells -> m_Right == nullptr );
  assert ( m . m_Rows -> m_Next -> m_Next -> m_Next -> m_Next == nullptr );
  assert ( m . m_Cols
           && m . m_Cols -> m_Idx == 0
           && m . m_Cols -> m_Cells
           && m . m_Cols -> m_Cells -> m_Row == 1
           && m . m_Cols -> m_Cells -> m_Col == 0
           && m . m_Cols -> m_Cells -> m_Data == 20
           && m . m_Cols -> m_Cells -> m_Down == nullptr );
  assert ( m . m_Cols -> m_Next
           && m . m_Cols -> m_Next -> m_Idx == 1
           && m . m_Cols -> m_Next -> m_Cells
           && m . m_Cols -> m_Next -> m_Cells -> m_Row == 0
           && m . m_Cols -> m_Next -> m_Cells -> m_Col == 1
           && m . m_Cols -> m_Next -> m_Cells -> m_Data == 10
           && m . m_Cols -> m_Next -> m_Cells -> m_Down
           && m . m_Cols -> m_Next -> m_Cells -> m_Down -> m_Row == 2
           && m . m_Cols -> m_Next -> m_Cells -> m_Down -> m_Col == 1
           && m . m_Cols -> m_Next -> m_Cells -> m_Down -> m_Data == 40
           && m . m_Cols -> m_Next -> m_Cells -> m_Down -> m_Down == nullptr );
  assert ( m . m_Cols -> m_Next -> m_Next
           && m . m_Cols -> m_Next -> m_Next -> m_Idx == 5
           && m . m_Cols -> m_Next -> m_Next -> m_Cells
           && m . m_Cols -> m_Next -> m_Next -> m_Cells -> m_Row == 1
           && m . m_Cols -> m_Next -> m_Next -> m_Cells -> m_Col == 5
           && m . m_Cols -> m_Next -> m_Next -> m_Cells -> m_Data == 30
           && m . m_Cols -> m_Next -> m_Next -> m_Cells -> m_Down == nullptr );
  assert ( m . m_Cols -> m_Next -> m_Next -> m_Next
           && m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Idx == 190
           && m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Cells
           && m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Cells -> m_Row == 230
           && m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Cells -> m_Col == 190
           && m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Cells -> m_Data == 50
           && m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Cells -> m_Down == nullptr );
  assert ( m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Next == nullptr );
  assert ( m . m_Rows -> m_Cells == m . m_Cols -> m_Next -> m_Cells );
  assert ( m . m_Rows -> m_Next -> m_Cells == m . m_Cols -> m_Cells );
  assert ( m . m_Rows -> m_Next -> m_Cells -> m_Right == m . m_Cols -> m_Next -> m_Next -> m_Cells );
  assert ( m . m_Rows -> m_Next -> m_Next -> m_Cells == m . m_Cols -> m_Next -> m_Cells -> m_Down );
  assert ( m . m_Rows -> m_Next -> m_Next -> m_Next -> m_Cells == m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Cells );
  assert ( removeCell ( &m, 0, 1 ) );
  assert ( !removeCell ( &m, 0, 1 ) );
  assert ( !removeCell ( &m, 1, 2 ) );
  assert ( m . m_Rows
           && m . m_Rows -> m_Idx == 1
           && m . m_Rows -> m_Cells
           && m . m_Rows -> m_Cells -> m_Row == 1
           && m . m_Rows -> m_Cells -> m_Col == 0
           && m . m_Rows -> m_Cells -> m_Data == 20
           && m . m_Rows -> m_Cells -> m_Right
           && m . m_Rows -> m_Cells -> m_Right -> m_Row == 1
           && m . m_Rows -> m_Cells -> m_Right -> m_Col == 5
           && m . m_Rows -> m_Cells -> m_Right -> m_Data == 30
           && m . m_Rows -> m_Cells -> m_Right -> m_Right == nullptr );
  assert ( m . m_Rows -> m_Next
           && m . m_Rows -> m_Next -> m_Idx == 2
           && m . m_Rows -> m_Next -> m_Cells
           && m . m_Rows -> m_Next -> m_Cells -> m_Row == 2
           && m . m_Rows -> m_Next -> m_Cells -> m_Col == 1
           && m . m_Rows -> m_Next -> m_Cells -> m_Data == 40
           && m . m_Rows -> m_Next -> m_Cells -> m_Right == nullptr );
  assert ( m . m_Rows -> m_Next -> m_Next
           && m . m_Rows -> m_Next -> m_Next -> m_Idx == 230
           && m . m_Rows -> m_Next -> m_Next -> m_Cells
           && m . m_Rows -> m_Next -> m_Next -> m_Cells -> m_Row == 230
           && m . m_Rows -> m_Next -> m_Next -> m_Cells -> m_Col == 190
           && m . m_Rows -> m_Next -> m_Next -> m_Cells -> m_Data == 50
           && m . m_Rows -> m_Next -> m_Next -> m_Cells -> m_Right == nullptr );
  assert ( m . m_Rows -> m_Next -> m_Next -> m_Next == nullptr );
  assert ( m . m_Cols
           && m . m_Cols -> m_Idx == 0
           && m . m_Cols -> m_Cells
           && m . m_Cols -> m_Cells -> m_Row == 1
           && m . m_Cols -> m_Cells -> m_Col == 0
           && m . m_Cols -> m_Cells -> m_Data == 20
           && m . m_Cols -> m_Cells -> m_Down == nullptr );
  assert ( m . m_Cols -> m_Next
           && m . m_Cols -> m_Next -> m_Idx == 1
           && m . m_Cols -> m_Next -> m_Cells
           && m . m_Cols -> m_Next -> m_Cells -> m_Row == 2
           && m . m_Cols -> m_Next -> m_Cells -> m_Col == 1
           && m . m_Cols -> m_Next -> m_Cells -> m_Data == 40
           && m . m_Cols -> m_Next -> m_Cells -> m_Down == nullptr );
  assert ( m . m_Cols -> m_Next -> m_Next
           && m . m_Cols -> m_Next -> m_Next -> m_Idx == 5
           && m . m_Cols -> m_Next -> m_Next -> m_Cells
           && m . m_Cols -> m_Next -> m_Next -> m_Cells -> m_Row == 1
           && m . m_Cols -> m_Next -> m_Next -> m_Cells -> m_Col == 5
           && m . m_Cols -> m_Next -> m_Next -> m_Cells -> m_Data == 30
           && m . m_Cols -> m_Next -> m_Next -> m_Cells -> m_Down == nullptr );
  assert ( m . m_Cols -> m_Next -> m_Next -> m_Next
           && m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Idx == 190
           && m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Cells
           && m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Cells -> m_Row == 230
           && m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Cells -> m_Col == 190
           && m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Cells -> m_Data == 50
           && m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Cells -> m_Down == nullptr );
  assert ( m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Next == nullptr );
  assert ( m . m_Rows -> m_Cells == m . m_Cols -> m_Cells );
  assert ( m . m_Rows -> m_Cells -> m_Right == m . m_Cols -> m_Next -> m_Next -> m_Cells );
  assert ( m . m_Rows -> m_Next -> m_Cells == m . m_Cols -> m_Next -> m_Cells );
  assert ( m . m_Rows -> m_Next -> m_Next -> m_Cells == m . m_Cols -> m_Next -> m_Next -> m_Next -> m_Cells );
  freeMatrix ( &m );
  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
