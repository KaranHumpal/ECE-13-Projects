// Karan Humpal
// khumpal@ucsc.edu
#include <stdio.h>
#include <math.h>


//User libraries:
#include "BOARD.h"

#ifdef PIC32
// Microchip libraries
#include <xc.h>
#endif

//gcc Calculator.c BOARD.c Lab2_main.c -lm -Wall -o Calculator
// **** Declare function prototypes ****
double Add(double operand1, double operand2);
double Subtract(double operand1, double operand2);
double Divide(double operand1, double operand2);
double Multiply(double operand1, double operand2);
double AbsoluteValue(double operand);
double FahrenheitToCelsius(double operand);
double CelsiusToFahrenheit(double operand);
double Tangent(double operand);
double Average(double operand1, double operand2);
double Round(double operand);
char Quit='q';
char character;
double operand;
double operand1;
double operand2;


//add more prototypes here


void CalculatorRun(void)
{
    printf("\n\nWelcome to Karan's calculator program! Compiled at %s %s\n",__DATE__, __TIME__);
   // scanf(" %c", &character);
   // printf("Operator received was: %c\n", character);
    while (1){
   // printf("\n\nEnter a Operator\n");
    printf("Enter a Mathematical Operation to preform or press 'q' to quit: '+','-','*','/','a','m','c','f','t','r': ");
    scanf(" %c", &character);
    //printf("Operator received was: '%c'\n", character);
    if(character=='+'){
        printf("Valid Operator, You Chose Addition\n");
        printf("Enter your first operand: ");
        scanf("%lf",&operand1);
        printf("Enter your second operand: ");
        scanf("%lf",&operand2);
        //printf("You input %f and %f\n",operand1,operand2);
        double result=Add(operand1,operand2);
        printf("Result of (%f + %f): %f\n",operand1, operand2, result);
     
    }
        else if(character=='-'){
        printf("Valid Operator, You Chose Subtraction\n");
        printf("Enter your first operand: ");
        scanf("%lf",&operand1);
        printf("Enter your second operand: ");
        scanf("%lf",&operand2);
       // printf("You input %f and %f\n",operand1,operand2);
        double result=Subtract(operand1,operand2);
        printf("Result of (%f - %f): %f\n",operand1, operand2, result);
    }
        else if(character=='*'){
        printf("Valid Operator, You Chose Multiplication\n");
        printf("Enter your first operand: ");
        scanf("%lf",&operand1);
        printf("Enter your second operand: ");
        scanf("%lf",&operand2);
        //printf("You input %f and %f\n",operand1,operand2);
        double result=Multiply(operand1,operand2);
        printf("Result of (%f * %f): %f\n",operand1, operand2, result);
    }
        else if(character=='/'){
        printf("Valid Operator, You Chose Division\n");
        printf("Enter your first operand: ");
        scanf("%lf",&operand1);
        printf("Enter your second operand: ");
        scanf("%lf",&operand2);
       // printf("You input %f and %f\n",operand1,operand2);
        double result=Divide(operand1,operand2);
        printf("Result of (%f / %f): %f\n",operand1, operand2, result);
    }
        else if(character=='a'){
        printf("Valid Operator, You Chose Absolute Value\n");
        printf("Enter an operand: ");
        scanf("%lf",&operand);
        //printf("You input %f\n",operand);
        double result=AbsoluteValue(operand);
        printf("Result of (|%f|): %f\n",operand, result);
    }
      else if(character=='m'){
        printf("Valid Operator, You Chose Average\n");
        printf("Enter your first operand: ");
        scanf("%lf",&operand1);
        printf("Enter your second operand: ");
        scanf("%lf",&operand2);
        //printf("You input %f and %f\n",operand1,operand2);
        double result=Average(operand1,operand2);
        printf("Result of Average(%f and %f): %f\n",operand1, operand2, result);
    }
      else if(character=='c'){
        printf("Valid Operator, You Chose Fahrenheit to Celsius\n");;
        printf("Enter an operand: ");
        scanf("%lf",&operand);
        //printf("You input %f\n",operand);
        double result=FahrenheitToCelsius(operand);
        printf("Result of (%f degF ->C): %f\n",operand, result);
    }
      else if(character=='f'){
        printf("Valid Operator, You Chose Celsius to Fahrenheit\n");
        printf("Enter an operand: ");
        scanf("%lf",&operand);
        //printf("You input %f\n",operand);
        double result=CelsiusToFahrenheit(operand);
        printf("Result of (%f degC ->F): %f\n",operand, result);
    }
      else if(character=='t'){
        printf("Valid Operator, You Chose Tangent\n");
        printf("Enter an operand: ");
        scanf("%lf",&operand);
        //printf("You input %f\n",operand);
        double result=Tangent(operand);
        printf("Result of tan(%f): %f\n",operand, result);
    }
      else if(character=='r'){
        printf("Valid Operator, You Chose Round\n");
        printf("Enter an operand: ");
        scanf("%lf",&operand);
        //printf("You input %f\n",operand);
        double result=Round(operand);
        printf("Result of round(%f): %f\n",operand, result);
    }
      else if(character=='q'){
    printf("Goodbye\n");
    exit(0);
    }
    else{
        printf("Error, Not a Valid Operator\n");
    }
              }
    

    // Your code here
    BOARD_End();
    while (1);
    
    
}



//********************************************************************************
 double Add(double operand1, double operand2)
 {
     double result_add =(operand1+operand2);
     return result_add;
 }
// ********************************************************************************


/********************************************************************************
 * Define the Subtract function here.
 ********************************************************************************/
double Subtract(double operand1, double operand2)
{
	  double result_subtract =(operand1-operand2);
      return result_subtract;
}

/********************************************************************************
 * Define the Multiply function here.
 ********************************************************************************/
double Multiply(double operand1, double operand2)
{
    double result_multiply =(operand1)*(operand2);
    return result_multiply;
}

/********************************************************************************
 * Define the Divide function here.
 ********************************************************************************/
double Divide(double operand1, double operand2)
{
	double result_divide =(operand1)/(operand2);
    return result_divide;
}

/********************************************************************************
 * Define the Absolute Value function here.
 ********************************************************************************/
double AbsoluteValue(double operand)
{
    double result_abs =fabs(operand);
    return result_abs;
}

/*********************************************************************************
 * Define the Fahrenheit to Celsius function here.
 ********************************************************************************/
double FahrenheitToCelsius(double operand)
{
    double result_FtoC =5*(operand-32)/9;
    return result_FtoC;
}

/*********************************************************************************
 * Define the Celsius to Fahrenheit function here.
 ********************************************************************************/
double CelsiusToFahrenheit(double operand)
{
    double result_CtoF =(operand*1.8)+32;
    return result_CtoF;
}

/********************************************************************************
 * Define the Average function here.
 *******************************************************************************/
double Average(double operand1, double operand2)
{
    double result_avg =(operand1+operand2)/2;
    return result_avg;
}

/*********************************************************************************
 * Define the Tangent function that takes input in degrees.
 ********************************************************************************/
double Tangent(double operand)
{
    double result_tan =tan(operand);
    return result_tan;  
}
/*********************************************************************************
 * Define the Round function here.
 * In order to receive the extra credit your calculator MUST ALSO CORRECTLY utilize
 * this function.
 ********************************************************************************/
double Round(double operand)
{
    double result_round = (int) (operand < 0 ? (operand - 0.5) : (operand + 0.5));
    return result_round;
}


