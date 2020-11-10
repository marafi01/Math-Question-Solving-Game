/*********************************************************************
Program:       Simply Math Tutor
Programmer:    Mahmudul Amin Rafi
Date:          2020.09.30
Description:   This program is designed for playing a math game.
*********************************************************************/

#include <iostream> //a file that has all the things like cin,cout 
#include <cstdlib> // srand & rand,general purpose functions
#include <ctime> // holding texual representation of time
#include <string> // string data type
#include <limits> // limit
using namespace std; // standard namespace

int main() {

// declaring and initialize all variables
int num1 = 0;
int num2 = 0;
int questionType = 0;
int userAnswer = 0;
int correctAnswer = 0;
int i = 1; 
bool keepLooping = true;
int firstLetter = 'y';
int firstletter = 'n';

string userName = "?";
string questionOperator = "?";
string doYouWantToCont = "?";


//Displaying the welcome header
cout << "Welcome to the simple math Tutor" << endl;
cout << "================================" << endl;
cout << endl;

cout << "Please Enter Your UserName: "; //user name to address the user in the question
getline(cin, userName); //allowing for a space in the user’s name
//Outputing rules of the game
cout << userName;

//Outputing rules of the game
cout << " Welcome  to the Simple Math Tutor game!" << endl;
cout << "The rules of the game are simply." << endl;
cout << "1) You have to answer random addition, subtraction, multiplication, or division questions." << endl;
cout << "2) You will get three chances to answer each question correctly." << endl;
cout << "3) You will get the opportunity to end the game at any point after answering a question." << endl;
cout << "Now let's get started!  Here is your first question!" << endl;

srand(time(0)); //seed the random method with the current time
num1 = (rand() % 10) + 1; //generator the first random number between 1 and 10
num2 = (rand() % 10) + 1;//generator the second random number between 1 and 10
questionType = (rand() % 4);//generator the question type random number between 0 and 3;

//Using a switch statement, setup common variables that will be used for all math question types based on the third random number (0-3)
while (keepLooping) {
switch (questionType) {
case 0:
num1 += num2; 
correctAnswer = num1 + num2;
questionOperator  = " + "; 
break;

case 1:           
num1 -= num2;
correctAnswer = num1 - num2;
questionOperator = " - "; 
break;

case 2:
num1 *= num2;
correctAnswer = num1 * num2;
questionOperator = " * ";
break;

case 3:
num1 /= num2;
correctAnswer = num1 / num2;
questionOperator = " / ";
break;

//letting the user know that an invalid question type was generated (plus displaying the question type) and informing the program ended with an error -1return -1 as an error code   
default:
cout << "questionType " << questionType << " is null, program ended with -1 error code" << endl; 
return -1;
}

//for loop three attempts 
for(int i=1; i<=3; i++) {
cout << userName;
cout << " What is " << num1 << questionOperator <<num2 << "?"; //displaying question

while (!(cin >> userAnswer)) {
cin.clear(); // clear the input number
cin.ignore(numeric_limits<streamsize>::max(),'\n');//ignore all data in the  buffer
cout << "Invalid input! Please enter a number: ";
}// end of userAnswer while loop

cin.ignore(numeric_limits<streamsize>::max(),'\n');//ignore all data in the  buffer

//if correct, congrats else 3 attempts left
if (userAnswer == correctAnswer) {
cout << " Congratulations! Correct Answer!" << endl;
break;
}//end of if statement
else if (i == 3) {
cout << "Unfortunately, you are out of attempts. You will get it next time!" << endl;
cout << "The correct answer is " << correctAnswer << "." << endl;
break;
} else {//Displays if the user gets incorrect answer
cout << "Sorry, that is incorrect. Try again!" << endl;
cout << "You only have " << 3 - i << " attempts left." << endl;
} // end of if

}//end of for loop number of attempts

//keep looping until the user enters y or n for do you continue
while (true) {
string doYouWantToCont = "?";
cout << "Do you want to continue (y=yes, n=no): ";//do not advance to the next line
getline(cin,doYouWantToCont);//get the user input line first char or word

char firstletter = tolower(doYouWantToCont.at(0));//get the first letter lower case
if (firstletter == 'y') {
keepLooping = true;//to force outer while to keep loopingbreak;
break; //break out of inner do you want to continue while loop// end of if
}else if(firstletter == 'n') {
keepLooping = false;//to force outer while loop  to stop looping
break; //break out of inner while do you want to continue while loop 
} else {
cout << "Invalid input! Please try again."<< endl;
break;//keeplooping until 1st char y, n
}// end of else

cout << endl; 
}//end of do you continue while loop
} // outer while loop

//displaying thank you message
cout << "Thanks for playing the game." << endl;
cout << "Good bye." << endl;
//Ending the program
cout << "End of program." << endl;

return 0; 
}
