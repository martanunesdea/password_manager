/* database.h */
#ifndef DATABASE_H // include guard
#define DATABASE_H
#include <iostream>
#include "password.h"

int add_to_database(Password_entry*);
int get_from_database(std::string website);
int list_all_passwords(void);
std::string make_insert_command(std::string website, std::string password);

#endif
