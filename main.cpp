/*
 * Main source file for doc parser: calls UI and gets input
 * Author: Marta Nunes de Abreu
 * Date: 18/07/2020
 */
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
  string filename;
  fstream afile;

  cout << "This is the document parser program.\n";
  cout << "Enter a document name to be parsed: ";
  cin >> filename;

  cout << "Opening " << filename << "...\n";
  afile.open(filename, ios::in );

  if( !afile )
  {
    cout << "Error: File does not exist" << endl;
    return 1;
  }
  else
  {
    string line;
    getline(afile, line);
    cout << line << endl;
    /*
    while ( getline (afile,line) )
    {
      cout << line << '\n';
    }*/

    /* while( !afile.eof() )
    {
      afile >> ch;
      cout << ch;
    } */
    afile.close();
  }


  return 0;
}
