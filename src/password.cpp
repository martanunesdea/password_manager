/* Source file defining class "password"
 * Project name: Password Encoder
 * Author: Marta Nunes de Abreu
 * Date: 31-07-2020
 */
#include "password.h"
#include "database.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

const int kPasswordLength = 20;

int get_last_key(void);

Password_entry::Password_entry()
{
  // Password initiated
}

Password_entry::~Password_entry()
{
  // Password deleted
}

std::string Password_entry::get_password(void)
{
  return password_;
}


std::string Password_entry::get_website(void)
{
  return website_;
}

int Password_entry::create_password(void)
{
  std::cout << "Generating password..." << std::endl;

  std::vector<char> characters{'A','B', 'C', 'D','E','F','G','H','I','J','K','L','M','N','O','P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '?', '+', '-', '*', '%', '@', '#', '$', '&', '=', '^'};

  int range = characters.size();

  srand( time(NULL) );
  int randomNumber;
  std::string pw;
  for(int i = 0; i < kPasswordLength; i++)
  {
    randomNumber = (rand() % (range-1)) + 1;
    pw.push_back(characters.at(randomNumber));
  }
  this->password_ = pw;

  std::cout << "Your new password is: " << pw << std::endl;

  return 0;
}


int Password_entry::save_password_entry()
{
  std::string website;
  std::cout << " -> To save your password in the manager program, "
              " enter the site of the account created: ";
  std::cin.ignore();
  std::getline(std::cin, website, '\n');

  if( website.empty() )
  {
    std::cout << "error: Website field was empty, skipping saving" << std::endl;
  }
  if (website.find(" ") != std::string::npos)
  {
    char exit;
    std::cout << " -> To skip saving, enter 'x': ";
    std::cin >> exit;
    if(exit=='x')
      return -1;
  }

  this->website_ = website;
  return add_to_database(this);
}

int Password_entry::get_password_entry(void)
{
  std::cout << "What was the website name? ";
  std::cin.ignore();
  std::getline(std::cin, this->website_, '\n');

  while( this->website_.empty() )
  {
    std::cout << "warning: field was empty" << std::endl;
    std::cin >> this->website_;
  }

  return get_from_database(this->website_);
}
