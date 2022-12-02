// Karan Humpal
// khumpal@ucsc.edu
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//CMPE13 Support Library
#include "BOARD.h"


//gcc -Wall mml_test.c MatrixMath.c BOARD.c -lm -o mml_test

// User libraries:
#include "MatrixMath.h"
float MatrixDeterminant2x2(float mat[2][2]); //Helper Function for Determinant 
int MatrixTwobyTwo(float mat1[2][2], float mat2[2][2]); //Helper Function for Submatrix

void MatrixPrint(float mat[3][3]){
  printf("______________________\n");   
int r, c;                            
for (r = 0; r < 3; r++) {       //first iterates through rows 
    printf("|");                 
    for (c = 0; c < 3; c++) { //Then iterates through columns
            printf("%3.4f|",mat[r][c]); //Prints the value in the position of its corresponding r,c
        }
    printf("\n");
    printf("----------------------\n"); 
    }


}
int MatrixEquals(float mat1[3][3], float mat2[3][3]){
int r, c;
float result=0;
for (r = 0; r < 3; r++) {
    for (c = 0; c < 3; c++) {
        result = mat1[r][c]-mat2[r][c]; //finds difference between two 3x3 matrices
        result = fabs(result);    //takes absolute value of the float
        if(result <= FP_DELTA){         //if the difference is <= FP Delta, we say they are equal
         continue;
        }
        else{
                     return 0;
                 }
            }
        }
return 1;
}   

void MatrixAdd(float mat1[3][3], float mat2[3][3], float result[3][3]){
    int r, c;
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) { 
        result[r][c] = mat1[r][c]+mat2[r][c];  //simply adds matricies
        //printf("%3.1f ",result[r][c]);
        }  
    }
}

void MatrixMultiply(float mat1[3][3], float mat2[3][3], float result[3][3]){
    int r, c, n;
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            result[r][c]=0; //initialize matrix
            for(n = 0; n < 3; n++) { // uses a third loop to specify position within the rows and columns in matrix
              result[r][c] += mat1[r][n] * mat2[n][c];  //this takes the first element in the first row and multiplies it by the first element
            }                                           // in the fist column and so onward as it iterates through the loops
            //printf("%3.1f ",result[r][c]);
        } // printf("\n");
    } //printf("\n");
}
void MatrixScalarAdd(float x, float mat[3][3], float result[3][3]){
    int r, c;
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) { 
        result[r][c] = mat[r][c]+x;
        }
    }
}
void MatrixScalarMultiply(float x, float mat[3][3], float result[3][3]){
    int r, c;
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
        result[r][c] = mat[r][c]*x;
        }
    }
}
float MatrixTrace(float mat[3][3]){
    int r;
    float trace=0; //initialize trace value
    for (r=0; r<3; r++){
        trace += mat[r][r]; //Use mat[rl[r] because as we continue to do r++ while r<3
    }                               //the values of the diagonal of the matrix return
    return trace;                   // we then add this to put previous value of trace to get the sum of the diagonal 
}


void MatrixTranspose(float mat[3][3], float result[3][3]){
    int r,c;
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
        result[r][c] = mat[c][r]; //Switching r and c would make the row values the original column values and the column values the original row values
        }
    }
}

void MatrixSubmatrix(int i, int j, float mat[3][3], float result[2][2]){
    int a = 0;  // initialize a and b
    int b = 0; 
    for (int r = 0; r < 3; r++) {
        if (r != i) {                       //if the row is not the one we are removing we continue to see if the column is the one we are removing 
            for (int c = 0; c < 3; c++) {
                if (c != j) {
                    result[a][b] = mat[r][c];  //Resulting is a 2x2 matrix
                       b++;      //increment b
                }else {
                    continue;
                }
            } 
        }else {
            continue;
        }a++; //increment a
        b=0;  //re initialize b
    }  
}

int MatrixTwobyTwo(float mat1[2][2], float mat2[2][2]){
int r, c;
float result=0;
for (r = 0; r < 2; r++) {               //helper function, Same as MatrixEquals() just for 2x2's
    for (c = 0; c < 2; c++) {
        result = mat1[r][c]-mat2[r][c];
        result = fabs(result);
        if(result <= FP_DELTA){
         continue;
        }
        else{
                     return 0;
                 }
            }
        }
return 1;
    }
float MatrixDeterminant2x2(float mat[2][2]){
    float result = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]); //Helper function, takes the determinant of a 2x2 
    return result; 
}

float MatrixDeterminant(float mat[3][3]){
    float sm1[2][2], sm2[2][2], sm3[2][2]; //These are where we hold the submatricies of mat
    
    MatrixSubmatrix(0,0,mat,sm1);  //We find the submatricies 
    MatrixSubmatrix(0,1,mat,sm2);
    MatrixSubmatrix(0,2,mat,sm3);
    
    float result1 = MatrixDeterminant2x2(sm1); //Find the determinant of the submatricies
    float result2 = MatrixDeterminant2x2(sm2);
    float result3 = MatrixDeterminant2x2(sm3);
    
    float determinant = (mat[0][0]*result1)-(mat[0][1]*result2)+(mat[0][2]*result3); //Using the determinant of the submatricies and the postion of values in the matrix 
           // printf("%f",determinant);                                              we are able to find the determinant of the 3x3. 
            return determinant;
            
}
void MatrixInverse(float mat[3][3], float result[3][3]){
    //First find the Cofactor Matrix
 
    int r,c;
    float resultSub1[2][2];
    float resultDet;
    float cofactor[3][3]={{},{},{}};
    
    

    
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            MatrixSubmatrix(r,c,mat,resultSub1);  //Cofactor matrix is found by taking the determinant of the submatricies of mat
            resultDet=MatrixDeterminant2x2(resultSub1);
            cofactor[r][c]=resultDet;
        }
    
}
    //we have to multiply the positions when r+c are odd by -1
    //if r+c is even we don't do anything 
    cofactor[1][0]*= -1;
    cofactor[0][1]*= -1;
    cofactor[1][2]*= -1;
    cofactor[2][1]*= -1;
            
            // Transpose the Cofactor matrix
    int determinant = MatrixDeterminant(mat);
    float transpose[3][3];
    float recipDet = 1/determinant;
    MatrixTranspose(cofactor,transpose);
        if(determinant==0){
        printf("Can not divide by 0, inverse matrix cannot be found");
    }
    // Multiply transposed matrix by 1/determinant 
    MatrixScalarMultiply(recipDet,transpose,result);
}


