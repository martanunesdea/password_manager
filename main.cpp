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
#include <algorithm>
#include "password.h"
#include <time.h>

const int kPasswordLength = 20;

int program_menu()
{
  int menuOption;
  std::cout << "This a password manager program, choose your option from the menu: \n";
  std::cout << "1) Generate a new password \n";
  std::cout << "2) Retrieve a password \n";
  std::cout << "3) List of encrypted passwords \n";

  std::cin >> menuOption;
  while ( menuOption > 3 || menuOption < 1)
  {
    std::cout << "Please enter a valid option\n";
    std::cin >> menuOption;
  }
  return menuOption;
}

void print_password(std::vector<char> pass)
{
  for(auto&& i : pass)
  {
    std::cout << i;
  }
  std::cout << "\n";
}

std::vector<char> random_password_generator(void)
{
  std::vector<char> characters{'A','B', 'C', 'D','E','F','G','H','I','J','K','L','M','N','O','P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '?', '+', '-', '*', '%', '@', '#', '$', '&', '=', '^'};

  int range = characters.size();

  srand( time(NULL) );
  int randomNumber;
  std::vector<char> pw;
  for(int i = 0; i < kPasswordLength; i++)
  {
    randomNumber = (rand() % (range-1)) + 1;
    pw.push_back(characters.at(randomNumber));
  }
  std::cout << "size of password: " << pw.size() << std::endl;

  return pw;
}


void save_new_password(std::vector<char> newPassword )
{
  std::string website, date;
  std::cout << "\n\nTo save your password in the manager program,\n"

            << " -> enter the site of the account created: ";
  std::cin.ignore();
  std::getline(std::cin, website, '\n');
  if( website.empty() )
  {
    std::cout << "warning: field was empty" << std::endl;
  }

  std::cout << " -> enter the date of account creation:";
  std::getline(std::cin, date, '\n');
  if( date.empty() )
  {
    std::cout << "warning: date was empty" << std::endl;
  }

  Password entry;
  entry.add_password_entry(website, date, newPassword);
  //int key = entry.add_password_entry(website, date, random_password_generator() );
  //entry.get_password(key);

}

void ask_user_to_save_password(std::vector<char> password)
{
  char answer;
  std::cout << "Would you like to save your password (y/n) ";
  std::cin >> answer;
  if (answer == 'y' || answer == 'Y')
  {
    save_new_password(password);
  }
}

std::vector<char> generate_new_password(void)
{
  std::string website;
  std::string date;

  auto newPassword = random_password_generator();
  std::cout << "Your new password is: ";
  print_password(newPassword);

  return newPassword;
}


int main(){

  int menu_option = program_menu();
  switch(menu_option)
  {
    case 1:
    {
      auto password = generate_new_password();
      ask_user_to_save_password(password);
      break;
    }
    case 2:
      std::cout << "second menu option chosen\n";
      break;
    case 3:
      std::cout << "third menu option chosen\n";
      break;
    default:
      std::cout << "Default case\n";
      break;
  }


  return 0;

}
