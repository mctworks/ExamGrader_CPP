/*CIST2362 Burley
Michael Thompson
Chapter 7 Program 10: Exam Grader
Description: This program is designed to read the answers to a test, then
read a text file with a student's answers, then calculate and display the
number of incorrect answers, their correct answers, the grade, and weither
or not the student passed or failed.*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> //For opening the text files
using namespace std;

void missed(char, char, int, int&); //Tallies and displays incorrect answers. 
void passOrFail(float); //Calculates and displays a Passing or Failing grade.

int main()
{
	ifstream correctFile;	//For opening the "CorrectAnswers" text file
	ifstream studentFile;	//For opening the "StudentAnswers" text file
	const int MAX = 20;		//Holds the maximum number of questions
	char answers[MAX];		//Array holding correct answers
	char student[MAX];		//Array holding student's answers
	int miss = 0;			//Number of missed questions
	char temp;				//Temp file used to store array results
	float grade;			//Student's grade
	
	//Opening the answer key into the program with notification.
	correctFile.open("CorrectAnswers.txt");	
	cout << "Now opening Correct Answers file..." << endl;

	//Each answer will be stored to a temp file, then into the character
	//array for all 20 questions.
	for(int i = 0; correctFile && i < MAX; ++i)
	{
		correctFile >> temp;
		answers[i] = temp;
	}

	//Opening a student's answers text file into the program
	studentFile.open("StudentAnswers.txt");
	cout << "Now opening Student Answers file..." << endl;

	//The student's answers are stored in the same way the
	//key's answers were, only in a seperate array.
	for(int i = 0; studentFile && i < MAX; ++i)
	{
		studentFile >> temp;
		student[i] = temp;
	}

	//Both files are now stored in char arrays, so we can close
	//the files now as they're no longer needed.
	correctFile.close();
	studentFile.close();

	//The "missed" function works until the maximum of 20 is reached.
	for (int k = 0; k <= MAX; k++)
	{
		missed(student[k], answers[k], k, miss);
	}

	//Informs the student how many questions were wrong,
	//and then calculates the grade.
	cout << "You missed " << miss << " questions." << endl;
	grade = (20.0 - miss) / 20.0;

	passOrFail(grade);

	system("pause");
	return 0;
}

/*This function compares each student answer to the correct answer,
one by one. If the two don't match, the program lists the question
number, what they answered with, and the correct answer. The number
of wrong answers is referenced back.*/
void missed(char s, char a, int q, int &wrong)
{
	if (s != a)
	{
		cout << "For Question " << q + 1 << " you answered " << endl;
		cout << s << ". The correct answer was " << a << "." << endl;
		wrong += 1;
	}
}

/*This function displays to the student their grade on the test, then
informs them if they passed or failed.*/
void passOrFail(float g)
{
	cout << "Your grade is " << g * 100 <<"%." << endl;

	if (g >= .7)
	{
		cout << "YOU PASSED!" << endl;
	}

	else
	{
		cout << "You Failed..." << endl;
	}
}