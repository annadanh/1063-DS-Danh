#include <iostream>
#include <fstream>
#include <string>
#include "DBList.h"

using namespace std;
  

int main() {
  DBList k;
  string a,tdata;
  int seed, Xmult, mult;
  int count = 0;
  int rCount = 0; // counts number of animals removed from list
  ifstream infile;
  infile.open("animals.txt");
  ofstream outfile;
  outfile.open("eliminated.txt");
  
// prints to the outfile the name of the program, my name, date, //program's description, and other info.
  outfile << "///////////////////////////////////////////////////////////////////\n";
  outfile << "// ProgramName: Program Three - Survival of the Lucky\n";
  outfile << "// Author: Anna Danh\n";
  outfile << "// Description: This program reads in a file of animl names and puts them into a list. It prompts the user to enter a random seed number and a multiplier that's between 1 and 13 inclusive and calculates the multiplier using that number to traverse the list. The program deletes the node it lands on. It repeats this process untill 1 animal remains and that animal is declared the winner.\n";
  outfile << "// Course: 1063 Data Structures\n";
  outfile << "// Semester: Spring 2018\n";
  outfile << "// Date: 27 04 2018\n";
  outfile << "///////////////////////////////////////////////////////////////////\n\n\n";

  
  cout << "Please enter a random seed number.\n";
  cin >> seed;
  cout << "Please enter an integar multiplier between 1 and 13 inclusive.\n";
  cin >> Xmult;
  // loops if number the user entered is out of the range
  while(Xmult < 1 || Xmult > 13){
    cout << "The number you entered isn't between 1 and 13.\n Please enter a number between 1 and 13 inclusive.\n\n";
  }
  
  srand(seed);
  
  while(!infile.eof()){
    infile >> a;
    count++;
    k.InsertRear(a);
  }
 
infile.clear();
infile.seekg(0, std::ios::beg);// goes back to start of file
 
while(!infile.eof()){
  infile >> a;
  for(int i=count; i>1; i--){
    mult = a.length() * Xmult;
    tdata = k.Traverse(mult);
    infile >> a;
    if(rCount==0){
      outfile << "First: " << tdata << '\n';
    }else if(rCount%11==0){
      outfile << "- " << tdata << '\n';
    }
    rCount++;
  }
}

outfile << "\nWINNER: " << tdata << "!!!!";
  
}
