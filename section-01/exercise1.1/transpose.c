#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Matrix struct contains number of rows, number of columns, and 1D data array
typedef struct {
    int rows;
    int cols;
    float data[MAX_ROWS * MAX_COLS];
} matrix_t;

// Function to create a new matrix and initialize data elements to 0.0
matrix_t create_matrix(int num_cols, int num_rows){
    matrix_t new_matrix;

    // Don't allow the number of rows/columns to exceed maximum capacity
    if(num_cols > MAX_COLS) num_cols = MAX_COLS;
    if(num_rows > MAX_ROWS) num_rows = MAX_ROWS;

    new_matrix.rows = num_rows;
    new_matrix.cols = num_cols;

    // Initialize all positions in the matrix to 0.0
    for(int i = 0; i<num_rows*num_cols; i++){
        new_matrix.data[i] = 0.0f;
    }
    
    return new_matrix;
}

// function to output the matrix rows to stdout
void print_matrix(matrix_t *m){
    for(int i = 0; i<m->rows; i++){
        for(int j = 0; j<m->cols; j++){
            // current element is i * num_cols + j in 1D array representation
            printf("%f", m->data[i*m->cols+j]);
            // don't add space at row ends
            if(j != m->cols-1) printf(" ");
        }
        // separate each row with a newline
        printf("\r\n");
    }
}

/* Helper function to swap opposite matrix elements in place
 * 
 * params:
 * m, pointer to matrix to transpose
 * row / col, integers, location of upper element in transpose pair
 *
 * return: 
 * no return, matrix elements swapped in place
 */
void transpose_element(matrix_t *m, int row, int col){
    float temp = m->data[row*m->cols+col];
    m->data[row*m->cols+col] = m->data[col*m->rows+row];
    m->data[col*m->rows+row] = temp;
}

/* Function to transpose a matrix in place
 * 
 * params:
 * m, pointer to matrix to transpose
 * 
 * return:
 * no return, matrix transposed in place
 * 
 * Notes:
 * It is more efficient to swap two elements in a matrix in place
 * than to copy every element one by one.
 *
 * This eliminates about half of the nested loop iterations.
 *
 * The following function implements this behavior by accepting
 * a pointer to an existing matrix and swapping elements in place.
 *
 * This makes the function more memory efficient (no additional
 * matricies or copies are needed). As a trade off, the original
 * state of the matrix is lost, and the transpose operation cannot
 * be chained with other operations inline.
 */
void transpose_matrix(matrix_t *m) {
    for (int i = 0; i < m->rows; ++i) {
        for (int j = i+1; j < m->cols; ++j) {
            transpose_element(m, i, j);
        }
    }
}

int main(){
    int num_rows = 4;
    int num_cols = 4;

    // create the matrix to be transposed
    matrix_t matrix = create_matrix(num_rows, num_cols);

    // set each position in the matrix to its row number
    for(int i = 0; i<matrix.rows; i++){
        for(int j = 0; j<matrix.cols; j++){
            matrix.data[i*matrix.cols+j] = i+1;
        }
    }

    // show original matrix
    printf("Original Matrix:\r\n");
    print_matrix(&matrix);
    // transpose the original matrix
    transpose_matrix(&matrix);
    // show show transposed matrix
    printf("\nTransposed Matrix:\r\n");
    print_matrix(&matrix);

    // indicate successful completion
    printf("\nApplication completed successfully.\r\n");

    return 0;
}