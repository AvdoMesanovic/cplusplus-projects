//*****************************************************************************************************
//
//		File:					rpn.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #9
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					April 12th, 2023
//
//
//		This program uses a templated Stack to evaluate RPN expressions.
//	
//		Other files required: 
//			1. stack.h - definition of the Stack class
//			2. expressions.txt - RPN expressions used for input
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;
#include "stack.h"

//*****************************************************************************************************

void outputToken(char token[], ofstream& resultsFile);
void processNumber(char token[], Stack<int>& rpnStack, ofstream& resultsFile);
bool processOperator(char mathOpr, Stack<int>& rpnStack, ofstream& resultsFile);
void displayResult(Stack<int>& rpnStack, bool isValid, ofstream& resultsFile);
void resetFlagStack(Stack<int>& rpnStack, bool& isValid);

//*****************************************************************************************************

int main()
{
    Stack<int> rpnStack;
    ifstream expFile("expressions.txt");
    ofstream resultsFile("results.txt");
    bool isValid = true;
    char token[5];

    while (expFile >> token)
    {
        outputToken(token, resultsFile);

        if (token[0] == ';')
        {
            displayResult(rpnStack, isValid, resultsFile);
            resetFlagStack(rpnStack, isValid);
        }
        else if ((isValid) && (isdigit(token[0])))
        {
            processNumber(token, rpnStack, resultsFile);
        }
        else if ((isValid && (ispunct(token[0]))))
        {
            if (!processOperator(token[0], rpnStack, resultsFile))
            {
                isValid = false;
            }
        }
    }

    expFile.close();
    resultsFile.close();

    return 0;
}

//*****************************************************************************************************

void outputToken(char token[], ofstream& resultsFile)
{
    resultsFile << endl << " ( Token: " << token << " ) \t\t";

    if (token[0] != ';')
    {
        cout << token << " ";
    }
}

//*****************************************************************************************************

void processNumber(char token[], Stack<int>& rpnStack, ofstream& resultsFile)
{
    int num = atoi(token);
    rpnStack.push(num);

    resultsFile << "Push " << num;
}

//*****************************************************************************************************

bool processOperator(char mathOpr, Stack<int>& rpnStack, ofstream& resultsFile)
{
    bool isValid = false;
    int op1,
        op2,
        result;

    if (rpnStack.pop(op2) && rpnStack.pop(op1))
    {
        switch (mathOpr)
        {
        case '+':
            result = op1 + op2;
            break;
        case '-':
            result = op1 - op2;
            break;
        case '*':
            result = op1 * op2;
            break;
        case '/':

            result = op1 / op2;
            break;
        case '%':
            result = op1 % op2;
            break;
        }

        rpnStack.push(result);
        resultsFile << "Pop: " << op2 << "\t" << "Pop: " << op1 << "\t"
            << "Push: " << result;
        isValid = true;
    }

    return isValid;
}

//*****************************************************************************************************

void displayResult(Stack<int>& rpnStack, bool isValid, ofstream& resultsFile)
{
    bool test;
    int value,
        result;

    rpnStack.pop(result);
    test = rpnStack.pop(value);

    if (test)
    {
        resultsFile << "Invalid RPN expression - too many operands" << endl << endl;
        cout << "\t\tInvalid" << endl;
    }
    else if (isValid)
    {
        resultsFile << "Valid: result = " << result << endl << endl;
        cout << "= " << result << endl;
    }
    else
    {
        resultsFile << "Invalid RPN expression - not enough operands" << endl << endl;
        cout << "\t\tInvalid" << endl;
    }
}

//*****************************************************************************************************

void resetFlagStack(Stack<int>& rpnStack, bool& isValid)
{
    int temp;

    while (rpnStack.pop(temp));
    isValid = true;
}

//*****************************************************************************************************

//2 4 * 5 + = 13
//13 5 % 5 + = 8
//15 1 + 2 / 1 - = 7
//15 + 1 + 2 / 1 -                Invalid
//3 4 + 15 10 - * = 35
//3 4 + 6 15 10 - *               Invalid
//2 13 + 14 6 - - 5 * 4 + = 39
//35 6 4 2 2 / + * - = 5
//3 4 + 1 2 - * 4 2 / 3 - + = -8
//3 14 1 2 4 2 3 + % * + - + = 8
