/*
 * Main source file for doc parser: calls UI and gets input
 * Author: Marta Nunes de Abreu
 * Date: 18/07/2020
 */
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
  string filename;
  ifstream f;
 cout << "This is the document parser program.\n";
  cout << "Enter a document name to be parsed: ";
  cin >> filename;

  cout << "Opening " << filename << "...\n";
  f.open(filename);

  if( !f )
  {
    cout << "Error: File does not exist" << endl;
    return 1;
  }
  string word;
  vector<string> text;

  size_t found_txt = filename.find(".txt");
  if(  found_txt!= string::npos )
  {
    cout << "You've uploaded a text file" << filename.find(".txt")  << endl;
    while( !f.eof() )
    {
      getline(f, word, ' ');
      cout << word << endl;
      text.push_back(word);
    }
  }

  size_t found_csv = filename.find(".csv");
  if( found_csv != string::npos)
  {
    cout << "You've uploaded a comma delimited file" << endl;
    while( !f.eof() )
    {
      getline(f, word, ',');
      cout << word << "\t";
      text.push_back(word);
    }
  }





  f.close();


  return 0;
}
