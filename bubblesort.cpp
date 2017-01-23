#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
int number[100];
int choice();
void bubbleSort(int[], int length);
void display();
int n;
int swapCount = 0;
int compCount = 0;
int FLAG;
int main()
{
  /* code */
  int x = choice();
  int i;
  ofstream swapFile;
  ofstream compFile;
  ofstream numFile;
  // For user input variables
  if (x == 1)
  {
    i = 0;
    char chi;    
    do{
      cout << "Enter a number" << endl;
      cin >> number[i];
      i++;
      cout << "Do you want to enter another number?" << endl;
      cin >> chi;
    }while (chi == 'Y' || chi == 'y');
    n = i;
    number[i] = '\0';
  }
  else if (x == 2)
  {
    srand((int)time(0));
    cout << "How many random numbers do you want to generate?" << endl;
    cin >> n;
    for (i = 0; i < n; i++)
    {
      number[i] = (rand() % 100) + 1;
    }
    number[i] = '\0';
    
  }
  display();
  cout << endl << endl;
  bubbleSort(number, n);
  display();
  cout << endl << endl;
  cout << "Number of swaps: " << swapCount << endl;
  cout << "Number of comparisons" << compCount;
  swapFile.open("swaps.txt", ios::app);
  compFile.open("comp.txt", ios::app);
  numFile.open("numbers.txt", ios::app);
  swapFile << swapCount << endl;
  compFile << compCount << endl;
  numFile << n << endl;
  return 0;
}

int choice()
{
  int inp;
  cout << "Bubble sort using:" << endl 
       << "1. User Input" << endl 
       << "2. Randomly generated" << endl;
  cin >> inp;
  if (inp == 1 || inp == 2)
  {
    return inp;
  }
  else
  {
    choice();
  } 
}

void swap(int &a, int &b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
  FLAG = 1;
  swapCount++;
}

void bubbleSort(int a[], int length)
{
  for (int i = 0; i < length; i++)
  {
    FLAG = 0;
    for (int j = 0; j < length-1; j++)
    {
      if(a[j] > a[j+1])
      {
        swap(a[j],a[j+1]);
      }
      compCount++;
    }
    if (FLAG != 1)
    {
      break;
    }
  }

}

void display()
{
  for (int i = 0; number[i] != '\0'; i++)
    {
      cout << number[i] << endl;
    }
}