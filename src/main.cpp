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


#define err 1
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

int main(){

  int menu_option = program_menu();
  switch(menu_option)
  {
    case 1:
    {
      Password_entry newPassword;
      if(newPassword.create_password()!=0)
        return err;
      if (newPassword.save_password_entry()!=0 )
        return err;
      break;
    }
    case 2:
    {
      Password_entry queriedPassword;
      if(queriedPassword.get_password_entry()!=0)
        return err;
      break;
    }
    case 3:
    {
      if(list_all_passwords()!=0)
        return err;
      break;
    }
    default:
    {
      std::cout << "Default case\n";
      break;
    }
  }


  return 0;

}
