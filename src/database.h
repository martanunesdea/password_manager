/* database.h */
#ifndef DATABASE_H // include guard
#define DATABASE_H
#include <iostream>
#include "password.h"

int save_password(Password_entry*);
int list_all_passwords(void);
std::string make_insert_command(std::string website, std::string password);

#endif
