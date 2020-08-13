/* Source file defining class "password"
 * Project name: Password Encoder
 * Author: Marta Nunes de Abreu
 * Date: 31-07-2020
 */
#include "password.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int get_last_key(void);

Password::Password()
{
  std::cout << "password initiated" << std::endl;
}

Password::~Password()
{
  std::cout << "password deleted" << std::endl;
}


void Password::add_password_entry(std::string site, std::string date, std::string password)
{
  website_ = site;
  date_ = date;
  password_ = password;

}

std::string Password::get_password(int key)
{
  return "hey";
}

void Password::save_password_entry(Password* pass)
{
  std::fstream f;
  f.open("database.txt", std::fstream::in | std::fstream::out | std::fstream::app);
  if ( !f.is_open() )
  {
    std::cout << "Failed to open file" << std::endl;
  }
  int passId = get_last_key();
  if (passId < 1)
  {
    pass->id_ = 1;
  }
  else{
    pass->id_ = passId+1;
  }
  std::cout << "id is " << passId << std::endl;
  f << "\n" << pass->id_ << "," << pass->website_ << "," << pass->date_ << "," << pass->password_ ;
  std::cout << "saved password" << std::endl;
  f.close();
}

int get_last_key(void)
{
  std::ifstream database;
  database.open("../database.txt");
  std::string line;
  std::getline(database,line,'\n');

  while( !database.eof() )
  {
    std::getline(database, line, '\n');
    std::cout << line << std::endl;
  }
  std::cout << "got final line " << line << std::endl;
  std::cout << "got last ID " << line.at(0) << std::endl;

  int lastId = line.at(0);
  return lastId;
}
