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
#include "database.h"
#include <time.h>
#include <mysqlx/xdevapi.h>



using namespace ::mysqlx;

int program_menu()
{
  int menuOption;
  std::cout << "This a password manager program, choose your option from the menu: \n";
  std::cout << "1) Generate a new password \n";
  std::cout << "2) Retrieve a password \n";
  std::cout << "3) List of all passwords \n";

  std::cin >> menuOption;
  while ( menuOption > 3 || menuOption < 1)
  {
    std::cout << "Please enter a valid option\n";
    std::cin >> menuOption;
  }
  return menuOption;
}

int save_password(std::string password)
{
  std::string website;
  std::cout << " -> To save your password in the manager program, "
              " enter the site of the account created: " << "\n"
            << " -> To skip saving, press 'x': ";
  std::cin.ignore();
  std::getline(std::cin, website, '\n');

  if( website.empty() )
    std::cout << "warning: field was empty" << std::endl;
  if (website.find("x") != string::npos)
    return -1;

  Password_entry entry;
  entry.make_password_entry(password, website);
  int result = entry.save_password_entry();
  return result;
}

std::string generate_new_password(void)
{
  return create_password();
}


int retrieve_password_entry(void)
{
  std::string website;
  std::cout << "What was the website name? ";
  std::cin.ignore();
  std::getline(std::cin, website, '\n');

  while( website.empty() )
  {
    std::cout << "warning: field was empty" << std::endl;
    std::cin >> website;
  }

  return retrieve_password(website);
}

int main(){

  int menu_option = program_menu();
  switch(menu_option)
  {
    case 1:
    {
      std::cout << "Generating password..." << std::endl;
      auto password = generate_new_password();
      std::cout << "your new password is " << password << std::endl;

      if ( save_password(password)!=0 )
      {
        //Error
        return 1;
      }

      break;
    }
    case 2:
      if(retrieve_password_entry()!=0)
      {
        // Error
        return 1;
      }
      break;
    case 3:
      if(list_all_passwords()!=0)
      {
        // Error
        return 1;
      }
      break;
    default:
      std::cout << "Default case\n";
      break;
  }


  return 0;

}
