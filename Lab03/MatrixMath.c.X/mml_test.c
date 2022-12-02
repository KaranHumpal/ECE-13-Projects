//Karan Humpal
//khumpal@ucsc.edu
// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//CMPE13 Support Library
#include "BOARD.h"




// User libraries:
#include "MatrixMath.h"

//gcc -Wall mml_test.c MatrixMath.c BOARD.c -lm -o mml_test
// Module-level variables:
float zero_matrix[3][3] = {{},{},{}};
int MatrixTwobyTwo(float mat1[2][2], float mat2[2][2]);


int main()
{
    int score =0;
    //Matrix Print
    BOARD_Init();
    printf("\n");
    printf("\n");

    printf("Beginning khumpal's mml test harness, compiled on %s %s\n", __DATE__, __TIME__);
    
    printf("Demonstrating MatrixPrint():\n");
    MatrixPrint(zero_matrix);
    //printf("\n"); 
    

    //Matrix Equals
    
    float sampleMatrix1[3][3] = {{0,0,0},{1,1,1},{2,2,2}};
    float sampleMatrix2[3][3] = {{0,0,0},{1,1,1},{2,2,2}};
    float sampleMatrix3[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    
    int x = MatrixEquals(sampleMatrix1, sampleMatrix2); //Test 1 compares 2 matrices that are of equal value and see what it returns
    int y = MatrixEquals(sampleMatrix2, sampleMatrix3); //Test 2 compares 2 matrices that are of unequal value and see what it returns
    
    if(x==1 && y==0){
        printf("PASSED (2/2): MatrixEquals()\n"); //The matrix is equal to the right one and not equal to the different one
        score+=1;
    }else if (x==1 && y==1){
         printf("PASSED (1/2): MatrixEquals()\n"); //The matrix is equal to the right one but also equal to the different one
    }else if (x==0 && y==0){
         printf("PASSED (1/2): MatrixEquals()\n"); //The matrix is not equal to neither the same one or the different one
    }else {
         printf("FAILED (0/2): MatrixEquals()\n");//The matrix is not equal to the same one but equal to the different one   
        }
    
    //Matrix Add 
    
    float addMatrix1[3][3] = {{1.5,2.5,3.5},{-1,-2,-3},{-3.5,4.0,2.5}};
    float addMatrix2[3][3]= {{-1.5,-2.5,-3.5},{1,2,3},{3.5,-4.0,-2.5}};
    float addMatrix3[3][3]= {{0,1,2},{3,4,5},{6,7,8}};
    float answer[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    float result1[3][3];
    float result2[3][3];
    MatrixAdd(addMatrix1,addMatrix2,result1);//Test 1 compares the result of our add function with a hard coded correct result
    int a = MatrixEquals(result1,answer);
    MatrixAdd(addMatrix2,addMatrix3,result2);//Test 2 compares the result of our add function with a hard coded incorrect result
    int b = MatrixEquals(result2,answer);
    
    if(a==1 && b==0){
        printf("PASSED (2/2): MatrixAdd()\n"); //The matrix is equal to the correct addition and != to the incorrect one
        score+=1;
    }else if (a==1 && b==1){
         printf("PASSED (1/2): MatrixAdd()\n"); //The matrix is equal to the correct addition and equal to the incorrect one
    }else if (a==0 && b==0){
         printf("PASSED (1/2): MatrixAdd()\n"); //The matrix is not equal to neither the correct addition or incorrect one
    }else {
         printf("FAILED (0/2): MatrixAdd()\n");//The matrix is not equal to the correct addition but equal to the incorrect one 
        }
    
   //Matrix Multiply
    float MultiplyMatrix1[3][3] = {{1.5,2.5,3.5},{-1,-2,-3},{-3.5,4.0,2.5}};
    float MultiplyMatrix2[3][3]= {{2,2,2},{2,2,2},{2,2,2}};
    float MultiplyMatrix3[3][3]= {{0,1,2},{3,4,5},{6,7,8}};
    float answerMultiply[3][3] = {{15,15,15},{-12,-12,-12},{6,6,6}};
    float resultMultiply1[3][3];
    float resultMultiply2[3][3];
    MatrixMultiply(MultiplyMatrix1,MultiplyMatrix2,resultMultiply1);//Test 1 compares the result of our multiply function with a hard coded correct result
    int d = MatrixEquals(resultMultiply1,answerMultiply);
    MatrixMultiply(MultiplyMatrix2,MultiplyMatrix3,resultMultiply2);//Test 2 compares the result of our multiply function with a hard coded incorrect result
    int e = MatrixEquals(resultMultiply2,answerMultiply);
    
    
        if(d==1 && e==0){
        printf("PASSED (2/2): MatrixMultiply()\n"); //The matrix is equal to the correct multiplication and != to the incorrect one
        score+=1;
    }else if (d==1 && e==1){
         printf("PASSED (1/2): MatrixMultiply()\n"); //The matrix is equal to the correct multiplication and equal to the incorrect one
    }else if (d==0 && e==0){
         printf("PASSED (1/2): MatrixMultiply()\n"); //The matrix is not equal to neither the correct multiplication or incorrect one
    }else {
         printf("FAILED (0/2): MatrixMultiply()\n");//The matrix is not equal to the correct multiplication but equal to the incorrect one 
        }
  // MatrixScalarAdd
    
    float resultScalarAdd1[3][3];//Test 1
    float scalarAddCorrect[3][3]={{3.5,4.5,5.5},{6.5,7.5,8.5},{9.5,10.5,11.5}};
    
    
    float resultScalarAdd2[3][3];//Test 2
    float scalarAddIncorrect[3][3]={{31,4.25,5.445},{12.5,7.5,34},{9.5,10.5,115}};
    
    float scalarAddMatrix1 [3][3]={{1,2,3},{4,5,6},{7,8,9}};
    float scalarAdd = 2.5;
    MatrixScalarAdd(scalarAdd,scalarAddMatrix1,resultScalarAdd1);
    MatrixScalarAdd(scalarAdd,scalarAddMatrix1,resultScalarAdd2);
    
    int scalarAddReturn1=MatrixEquals(resultScalarAdd1,scalarAddCorrect);
    int scalarAddReturn2=MatrixEquals(resultScalarAdd2,scalarAddIncorrect);
    
    if(scalarAddReturn1==1 && scalarAddReturn2==0){
         printf("PASSED (2/2): MatrixScalarAdd()\n"); //The matrix is equal to the correct scalar addition and != to the incorrect one
        score+=1;
    }else if (scalarAddReturn1==1 && scalarAddReturn2==1){
         printf("PASSED (1/2): MatrixScalarAdd()\n"); //The matrix is equal to the correct scalar addition and equal to the incorrect one
    }else if (scalarAddReturn1==0 && scalarAddReturn2==0){
         printf("PASSED (1/2): MatrixScalarAdd()\n"); //The matrix is not equal to neither the correct scalar addition or incorrect one
    }else {
         printf("FAILED (0/2): MatrixScalarAdd()\n");//The matrix is not equal to the correct scalar addition but equal to the incorrect one 
        }  
    
    //Matrix Scalar Multiply
    float resultScalarMultiply1[3][3];//Test 1
    float scalarMultiplyCorrect[3][3]={{.5,1,1.5},{2,2.5,3},{3.5,4,4.5}};
    
    
    float resultScalarMultiply2[3][3];//Test 2
    float scalarMultiplyIncorrect[3][3]={{31,4.25,5.445},{12.5,7.5,34},{9.5,10.5,115}};
    
    float scalarMultiplyMatrix1 [3][3]={{1,2,3},{4,5,6},{7,8,9}};
    float scalarMultiply = 0.5;
    MatrixScalarMultiply(scalarMultiply,scalarMultiplyMatrix1,resultScalarMultiply1);
    MatrixScalarMultiply(scalarMultiply,scalarMultiplyMatrix1,resultScalarMultiply2);
    
    int scalarMultiplyReturn1=MatrixEquals(resultScalarMultiply1,scalarMultiplyCorrect);
    int scalarMultiplyReturn2=MatrixEquals(resultScalarMultiply2,scalarMultiplyIncorrect);
    
    if(scalarMultiplyReturn1==1 && scalarMultiplyReturn2==0){
         printf("PASSED (2/2): MatrixScalarMultiply()\n"); //The matrix is equal to the correct scalar multiplication and != to the incorrect one
        score+=1;
    }else if (scalarMultiplyReturn1==1 && scalarMultiplyReturn2==1){
         printf("PASSED (1/2): MatrixScalarMultiply()\n"); //The matrix is equal to the correct scalar multiplication and equal to the incorrect one
    }else if (scalarMultiplyReturn1==0 && scalarMultiplyReturn2==0){
         printf("PASSED (1/2): MatrixScalarMultiply()\n"); //The matrix is not equal to neither the correct scalar multiplication or incorrect one
    }else {
         printf("FAILED (0/2): MatrixScalarMultiply()\n");//The matrix is not equal to the correct scalar multiplication but equal to the incorrect one 
        } 
    //Matrix Trace
    
    float traceMatrix1[3][3]={{-182.3,-78,674.2},{32.1,182.3,73463.22},{0,-4,-40.6}}; //Test 1
    float answerTrace1 = MatrixTrace(traceMatrix1);
    float traceCorrect = -40.6;
    
    float traceMatrix2[3][3]={{1,1,1},{1,1,1},{1,1,1}}; //Test 2
    float answerTrace2 = MatrixTrace(traceMatrix2);
    float traceIncorrect = 0;
    
    if(answerTrace1==traceCorrect && answerTrace2!=traceIncorrect){
          printf("PASSED (2/2): MatrixTrace()\n"); //The matrix is equal to the correct trace and != to the incorrect one
        score+=1;
    }else if (answerTrace1==traceCorrect && answerTrace2==traceIncorrect){
         printf("PASSED (1/2): MatrixTrace()\n"); //The matrix is equal to the correct trace and equal to the incorrect one
    }else if (answerTrace1!=traceCorrect && answerTrace2!=traceIncorrect){
         printf("PASSED (1/2): MatrixTrace()\n"); //The matrix is not equal to neither the correct trace or incorrect one
    }else {
         printf("FAILED (0/2): MatrixTrace()\n");//The matrix is not equal to the correct trace but equal to the incorrect one 
    }
    
    //Matrix Transpose 
    float transposeMatrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    
    float resultTransposeMatrix1[3][3]; //Test1
    float correctTransposeMatrix[3][3] = {{1,4,7},{2,5,8},{3,6,9}};
    MatrixTranspose(transposeMatrix,resultTransposeMatrix1);
    
    float resultTransposeMatrix2[3][3]; //Test2
    float incorrectTransposeMatrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    MatrixTranspose(transposeMatrix,resultTransposeMatrix2);
    
    float returnTranspose1 = MatrixEquals(correctTransposeMatrix,resultTransposeMatrix1);
    float returnTranspose2 = MatrixEquals(incorrectTransposeMatrix,resultTransposeMatrix2);
    
    if(returnTranspose1==1 && returnTranspose2==0){
            printf("PASSED (2/2): MatrixTranspose()\n"); //The matrix is equal to the correct transpose and != to the incorrect one
        score+=1;
    }else if (returnTranspose1==1 && returnTranspose2==1){
         printf("PASSED (1/2): MatrixTranspose()\n"); //The matrix is equal to the correct transpose and equal to the incorrect one
    }else if (returnTranspose1==0 && returnTranspose2==0){
         printf("PASSED (1/2): MatrixTranspose()\n"); //The matrix is not equal to neither the correct transpose or incorrect one
    }else {
         printf("FAILED (0/2): MatrixTranspose()\n");//The matrix is not equal to the correct transpose but equal to the incorrect one 
    }
    
    //SubMatrix
    
    float resultSub1 [2][2];
    float resultSub2 [2][2];
    float matrixSub[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    
    float correctSubmatrix[2][2]={{5,6},{8,9}};
    MatrixSubmatrix(0,0,matrixSub,resultSub1);
    float returnSubmatrix1= MatrixTwobyTwo(resultSub1,correctSubmatrix);
    
    float incorrectSubmatrix[2][2]={{5,12},{8,9}};
    MatrixSubmatrix(0,0,matrixSub,resultSub2);
    float returnSubmatrix2= MatrixTwobyTwo(resultSub2,incorrectSubmatrix);
    
    if(returnSubmatrix1==1 && returnSubmatrix2==0){
            printf("PASSED (2/2): MatrixSubMatrix()\n"); //The matrix is equal to the correct SubMatrix and != to the incorrect one
        score+=1;
    }else if (returnSubmatrix1==1 && returnSubmatrix2==1){
         printf("PASSED (1/2): MatrixSubMatrix()\n"); //The matrix is equal to the correct SubMatrix and equal to the incorrect one
    }else if (returnSubmatrix1==0 && returnSubmatrix2==0){
         printf("PASSED (1/2): MatrixSubMatrix()\n"); //The matrix is not equal to neither the SubMatrix transpose or incorrect one
    }else {
         printf("FAILED (0/2): MatrixSubMatrix()\n");//The matrix is not equal to the correct SubMatrix but equal to the incorrect one 
    }
    

    
    //Determinant
    float determinantMatrix1[3][3]={{-1,8,0},{5,-9,7},{9,6,0}};
    float determinantMatrix2[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    
    //Test1
    float resultDeterminant1 =  MatrixDeterminant(determinantMatrix1);
    float correctDeterminant1 = 546;

    
    //Test2
    float resultDeterminant2= MatrixDeterminant(determinantMatrix2);
    float incorrectDeterminant1 = 1;

    
    if(resultDeterminant1==correctDeterminant1 && resultDeterminant2!=incorrectDeterminant1){
            printf("PASSED (2/2): MatrixDeterminant()\n"); //The matrix is equal to the correct Determinant and != to the incorrect one
        score+=1;
    }else if (resultDeterminant1==correctDeterminant1 && resultDeterminant2==incorrectDeterminant1){
         printf("PASSED (1/2): MatrixDeterminant()\n"); //The matrix is equal to the correct Determinant and equal to the incorrect one
    }else if (resultDeterminant1!=correctDeterminant1 && resultDeterminant2!=incorrectDeterminant1){
         printf("PASSED (1/2): MatrixDeterminant()\n"); //The matrix is not equal to neither the correct Determinant or incorrect one
    }else {
         printf("FAILED (0/2): MatrixDeterminant()\n");//The matrix is not equal to the correct Determinant but equal to the incorrect one 
    }
    
    //Inverse 
    float inverseMatrix1[3][3]={{1,1,1},{-1,-1,0},{0,1,1}};
    
    //Test1
    float resultCorrectInverse[3][3]={{1,0,-1},{-1,-1,1},{1,1,0}};
    float resultInverse1[3][3];
    MatrixInverse(inverseMatrix1,resultInverse1);
    float returnInverse1 =MatrixEquals(resultCorrectInverse,resultInverse1);
    
    //Test2
    float resultIncorrectInverse[3][3]={{1,0,0},{-1,-1,1},{1,1,0}};
    float resultInverse2[3][3];
    MatrixInverse(inverseMatrix1,resultInverse2);
    float returnInverse2 =MatrixEquals(resultIncorrectInverse,resultInverse2);
    
    if(returnInverse1==1 && returnInverse2==0){
            printf("PASSED (2/2): MatrixInverse()\n"); //The matrix is equal to the correct Inverse and != to the incorrect one
        score+=1;
    }else if (returnInverse1==1 && returnInverse2==1){
         printf("PASSED (1/2): MatrixInverse()\n"); //The matrix is equal to the correct Inverse and equal to the incorrect one
    }else if (returnInverse1==0 && returnInverse2==1){
         printf("PASSED (1/2): MatrixInverse()\n"); //The matrix is not equal to neither the correct Inverse or incorrect one
    }else {
         printf("FAILED (0/2): MatrixInverse()\n");//The matrix is not equal to the correct Inverse but equal to the incorrect one 
    }
    
    float percent = (score*0.1) * 100;
    printf("%.0d out of 10 tests passed: %.0f%% \n", score, percent); //Determines how many correct functions out of 10, and the percentage 
    
    
    
    printf("\n");
    printf("Output of MatrixPrint(): \n");
    float sampleMatrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    MatrixPrint(sampleMatrix);
    
    
    printf("\n");
    printf("Expected output of MatrixPrint(): \n");
    printf("______________________\n");
    printf("|1.0000|2.0000|3.0000|\n");
    printf("----------------------\n");
    printf("|4.0000|5.0000|6.0000|\n");
    printf("----------------------\n");
    printf("|7.0000|8.0000|9.0000|\n");
    printf("---------------------- \n");
    BOARD_End();
    while (1);
    
}

