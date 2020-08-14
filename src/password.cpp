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

std::string create_password(void)
{
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
  std::cout << "size of password: " << pw.size() << std::endl;
  return pw;
}



int get_last_key(void);

Password_entry::Password_entry()
{
  std::cout << "password initiated" << std::endl;
}

Password_entry::~Password_entry()
{
  std::cout << "password deleted" << std::endl;
}

std::string Password_entry::get_password()
{
  return password_;
}


std::string Password_entry::get_website()
{
  return website_;
}


void Password_entry::make_password_entry(std::string password, std::string site)
{
  password_ = password;
  website_ = site;
}

int Password_entry::save_password_entry()
{
  return save_password(this);
}
