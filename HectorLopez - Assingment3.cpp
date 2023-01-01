// HectorLopez - Assingment3.cpp 
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

#define _GLIBCXX_USE_CXX11_ABI 0

/*
In this program we implemeted the given assingment functions, where we start off by reading a file
specifically named "LIST.txt" upon reading the formatted file we enter all of the values from the file
into a string array of size 100, and count the amount of values that we added into the string array. We
then call the given functions each with their own description.
*/

// Function declarations
void ReadConcepts(string ArrayConcepts[100], int& NumberConcepts);
void PrintAllConcepts(string ArrayConcepts[100], int NumberConcepts);
string EnterString();
void PrintConceptsWord(string ArrayConcepts[100], int NumberConcepts, string Word);
void PrintConceptsWithoutWord(string ArrayConcepts[100], int NumberConcepts, string Word);
void SortConcepts(string ArrayConcepts[100], int Number);

// Custom Function to format string 
string FormatString(string ogString);

int main()
{
    // Create required variables
    int NumberConcepts;
    string ArrayConcepts[100];
    
    // Function calls to the created functions
    ReadConcepts(ArrayConcepts, NumberConcepts);
    PrintAllConcepts(ArrayConcepts, NumberConcepts);
    PrintConceptsWord(ArrayConcepts, NumberConcepts, EnterString());
    PrintConceptsWithoutWord(ArrayConcepts, NumberConcepts, EnterString());
    SortConcepts(ArrayConcepts, NumberConcepts);
    PrintAllConcepts(ArrayConcepts, NumberConcepts);

    return 0;
}

// "LIST.txt" is opened and each line is stored in a string array of size 100
void ReadConcepts(string ArrayConcepts[100], int& NumberConcepts)
{
    // File stream variable
    ifstream file;
    file.open("LIST.txt");
    // String variable to hold file data
    string data;

    // Ensuring that file can be opened
    if (!file)
    {
        cout << "!! ERROR: FILE cannot be opened !!";
        return;
    }
    // If file did not fail then we can proceed to read file
    else
    {
        // Instantiate Numberconcepts to 0
        NumberConcepts = 0;
        
        // While loop that reads a line from the file, stores it in data variable until EOF
        while (getline(file,data))
        {
            // Insert the data variable into the String array
            ArrayConcepts[NumberConcepts] = data;
            // Increment the NumberConcepts for each line count
            NumberConcepts++;
        }
    }
 }

// Prints all string values from the array
void PrintAllConcepts(string ArrayConcepts[100], int NumberConcepts)
{
    // Ensures that ArrayConcepts is not empty
    if (NumberConcepts == 0) {
        // Prints out to console if Array is empty
        cout << "!! Empty ArrayConcepts - File Empty !!";
    }
    else {
        // Prints out format for ArrayConcepts
        cout << "--- The concepts are: \n";
        // For loop to output all values in ArrayConcepts each value on a newline
        for (int i = 0; i < NumberConcepts; i++) {
            cout << ArrayConcepts[i] << endl;
        }
    }
}

// Asks user to enter a String this function is used in Searches
string EnterString()
{
    // String for user Input
    string userInput;
    cout << "Enter a string :: ";
    cin >> userInput;

    // If user input is less than 2 characters then they are warned and function is called again
    if (userInput.length() < 2) {
        cout << "String length too short - Needs to be at least 2 characters \n";
        // recursive function call
        return EnterString();
    }
    return userInput;
}

// Prints all Concepts that match the given WORD exactly 
void PrintConceptsWord(string ArrayConcepts[100], int NumberConcepts, string Word)
{
    // Prints out format for Word
    cout << "--- The concepts containing " << Word << " are: \n";
    // Format word for finding instances in another string
    Word = FormatString(Word);

    // For loop that searrches through ArrayConcepts
    for (int i = 0; i < NumberConcepts; i++) {
        // Create a temporary string to format and compare
        string tempString = FormatString(ArrayConcepts[i]);
        // If temp String contains inputted Word
        if (tempString.find(Word) != string::npos) {
            // Prints to console the given concept that matches the WORD
            cout << ArrayConcepts[i] << endl;
        }
    }
}

// Prints all Concepts that do not match the given WORD exactly 
void PrintConceptsWithoutWord(string ArrayConcepts[100], int NumberConcepts, string Word)
{
    // Prints out format for Word
    cout << "--- The concepts that do not contain " << Word << " are: \n";
    // Format word for finding instances in another string
    Word = FormatString(Word);

    // For loop that searrches through ArrayConcepts
    for (int i = 0; i < NumberConcepts; i++) {
        // Create a temporary string to format and compare
        string tempString = FormatString(ArrayConcepts[i]);
        // If temp String contains inputted Word
        if (tempString.find(Word) == string::npos) {
            // Prints to console the given concepts that don't equal the WORD
            cout << ArrayConcepts[i] << endl;
        }
    }

}
// Sorts the ArrayConcepts in descending order
void SortConcepts(string ArrayConcepts[100], int NumberConcepts)
{
    // Necessary variables for Selection Sort
    int i, j, min;
    string minString;

    // Outter For loop for selection sort
    for (i = 0; i < NumberConcepts - 1; i++) {
        // Set minimum index to i
        min = i;
        // Set minimum string to indexed Array value
        minString = ArrayConcepts[i];

        // Inner For loop for Selection sort to compare to minString
        for (j = i + 1; j < NumberConcepts ; j++) {
            // If minString is less than the string next to it
            if (minString < ArrayConcepts[j] ) {
                // Set minString to the string next to it
                minString = ArrayConcepts[j];
                // Set new minimum index to minString Index
                min = j;
            } 
        }
        // If we set minString to a new string
        if (min != i) {
            // Temporary variable to hold string indexed at i
            string temp = ArrayConcepts[i];
            // Set string at index of i to string at minimum index
            ArrayConcepts[i] = ArrayConcepts[min];
            // Set string at minimum index to the temporary string
            ArrayConcepts[min] = temp;
        }
    }
}

// Iterates through the string and creates upper case characters for comparison
string FormatString(string ogstring){
    // Iterates through string
    for (int i = 0; i < ogstring.length(); i++){
        // Changes character in string to upper case
  		ogstring[i] = toupper(ogstring[i]);
  	}
    return ogstring;
}