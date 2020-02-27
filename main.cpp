// This program is a heap, allowing the user to input a set of numbers either manually by console or with a file, and it outputs the max heap binary tree and output.
// Ethan Wang
// 2/24/20

#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;
//Function Prototypes
void heap (int* array, int input, int count);
void build (int* array, int count);
void printree (int* array, int count, int input, int input2); 

//Main Line, Calls Functions, has UI 
int main() {
  char* input = new char[50];
  cout << "Do you want to input a 'file' or through 'console'? \n";
  cin.getline(input, 50);
  int count = 0;
  int* array = new int[250];
  //Console Input
  if(strcmp(input, "console") == 0) {
    cout << "Enter the numbers you want to add to the heap, seperate each one with a space \n";
    char* input2 = new char[250];
    cin.getline(input2, 250);
    char* token = strtok(input2, " ");
    int index = 1;
    while(token != NULL) {
      array[index] = atoi(token);
      token = strtok(NULL, " ");
      index++;
      count++;
    }
  }
  //File Input
  else if (strcmp(input, "file") == 0) {
    cout << "Filename? \n";
    char* filename = new char[50];
    cin.getline(filename, 50);
    ifstream inFile;
    inFile.open(filename);
    char* input2 = new char[250];
    int count2 = 0;
    int index2 = 1;
    while (inFile >> count2) {
      array[index2] = count2;
      index2++;
      count++;
    }
  }
  else {
    cout << "Please enter understandable input.";
  }
  //Builds Heap and Prints out Tree along with Regular Greatest to Least Output, Deletes Each Number After Printed in Output
  build(array, count);
  cout << "Tree: \n";
  printree(array, count, 0, 1); 
  cout << " " << endl; 
  cout << "Heap Output: ";
  for (int i = count; i > 0; i--) {
    cout << array[1] << " "; 
    array[1] = array[i];
    array[i] = 0; 
    build(array, i);
    array[i] = array[i - 1]; 
  }  
}
//Function to sort the Heap into greatest to least
void heap (int* array, int input, int count) {
  int index;
  int temp;
  temp = array[input];
  index = input*2;
  while (index <= count) {
    if (array[index+1] > array[index] && index < count)
      index = index + 1;
    if (temp > array[index])
      break;
    else if (temp <= array[index]) {
      array[index/2] = array[index];
      index = 2 * index;
    }
  }
  array[index/2] = temp;
  return; 
}

//Builds heap with entire array and heap sort function
void build (int* array, int count) {
  int i;
  for(i = count/2; i >= 1; i--) {
    heap(array, i, count); 
  }  
}

//Prints Max Heap Tree 
void printree (int* array, int count, int input, int input2) {
  int leftposition = 2*input2;
  int rightposition = 2*input2+1;
  if (rightposition <= count) {
    printree(array, count, input+1, rightposition); 
  }
  int current = input;
  while (input > 0) {
    cout << "    ";
    input--; 
  }
  cout << array[input2] << endl;
  if (leftposition <= count) {
    printree(array, count, current + 1, leftposition); 
  }
}
