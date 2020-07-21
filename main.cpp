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

struct file{
  string name;
  string termination;
  string filename;
};

void get_doc(struct file* doc)
{
  cout << "Welcome to the document parser program.\n";
  cout << "Please enter the name you wish to use for the program: ";
  getline(cin, doc->name, '.');
  getline(cin, doc->termination);
  doc->filename = doc->name + "." + doc->termination;
}
int program_menu()
{
  int menu_option;
  cout << "Select the option you wish to use: \n";
  cout << "1) Provide text metrics of document \n";
  cout << "2) Categorise document by topic \n";
  cout << "3) Encrypt document \n";

  cin >> menu_option;
  while ( menu_option > 3 || menu_option < 1)
  {
    cout << "Please enter a valid option\n";
    cin >> menu_option;
  }
  return menu_option;
}
void parse_doc(ifstream* f, struct file* doc)
{
  string word;
  vector<string> text;
  if( doc->termination=="txt" )
  {
    while( !f->eof() )
    {
      getline(*f, word, ' ');
      cout << word << endl;
      text.push_back(word);
    }
  }

  if( doc->termination==".csv" )
  {
    while( !f->eof() )
    {
      getline(*f, word, ',');
      cout << word << "\t";
      text.push_back(word);
    }
  }
}


int main(){
  file doc;
  int menu_option;
  ifstream f;

  get_doc(&doc);
  cout << "Opening " << doc.filename << "...\n";
  f.open(doc.filename);
  if( !f )
  {
    cout << "Error: File does not exist" << endl;
    return 1;
  }

  menu_option = program_menu();
  switch(menu_option)
  {
    case 1:
      cout << "Showing metrics of document\n";
      parse_doc(&f, &doc);
      break;
    case 2:
      cout << "second menu option chosen\n";
      break;
    case 3:
      cout << "third menu option chosen\n";
      break;
    default:
      cout << "Default case\n";
      break;
  }

  f.close();

  return 0;

}
