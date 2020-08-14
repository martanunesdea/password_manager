#include <iostream>
#include "database.h"
#include "password.h"
#include <mysqlx/xdevapi.h>

using namespace ::mysqlx;

int save_password(Password_entry *entry)
{
  /* TRY */
try {
  #warning change pwd
  /* SETUP SESSION, SCHEMA AND TABLE */
  const char *url = "mysqlx://root:pwd@127.0.0.1";
  Session sess(url);
  Schema sch= sess.getSchema("password_manager");
  sess.sql("USE password_manager").execute();

  /* INSERT PASSWORD */
  std::string insert = make_insert_command( entry->get_website(), entry->get_password() );
  std::cout << "Adding to database..."<< std::endl;
  sess.sql(insert).execute();

  std::cout <<"\nDone!" << std::endl;
  return 0;
  }

  /* CATCH */
  catch (const mysqlx::Error &err)
  {
    std::cout <<"ERROR: " <<err << std::endl;
    return 1;
  }
  catch (std::exception &ex)
  {
    std::cout <<"STD EXCEPTION: " <<ex.what() << std::endl;
    return 1;
  }
  catch (const char *ex)
  {
    std::cout << "EXCEPTION: " <<ex << std::endl;
    return 1;
  }
  return 0;
}

int retrieve_password(std::string website)
{
  #warning change pwd
  /* SETUP SESSION, SCHEMA AND TABLE */
  const char *url = "mysqlx://root:pwd@127.0.0.1";
  Session sess(url);
  Schema sch= sess.getSchema("password_manager");
  sess.sql("USE password_manager").execute();

  /* MAKE ENQUIRY */
  std::string select = "SELECT * FROM password_table WHERE account='";
  select += website;
  select += "';";
  RowResult res = sess.sql(select).execute();

  /* SHOW OUTPUT */
  Row row;
  while ((row = res.fetchOne())) {
    std::cout << "Account: " << row[1] << "\t Password: " << row[2] << std::endl;
  }


  return 0;
}


int list_all_passwords(void)
{
  /* TRY */
try {
  #warning change pwd
  /* SETUP SESSION, SCHEMA AND TABLE */
  const char *url = "mysqlx://root:pwd@127.0.0.1";
  Session sess(url);
  Schema sch= sess.getSchema("password_manager");
  sess.sql("USE password_manager").execute();

  RowResult res = sess.sql("SELECT account, password from password_table").execute();
  Row row;
  while ((row = res.fetchOne())) {
    std::cout << "Account: " << row[0] << "\t Password: " << row[1] << std::endl;
  }
  std::cout << "\nDone!" << std::endl;

  return 0;
  }

  /* CATCH */
  catch (const mysqlx::Error &err)
  {
    std::cout <<"ERROR: " <<err << std::endl;
    return 1;
  }
  catch (std::exception &ex)
  {
    std::cout <<"STD EXCEPTION: " <<ex.what() << std::endl;
    return -1;
  }
  catch (const char *ex)
  {
    std::cout << "EXCEPTION: " <<ex << std::endl;
    return -1;
  }
  return 0;
}


std::string make_insert_command(std::string website, std::string password)
{
  std::string insert = "INSERT INTO password_table (account, password) values ('";
  insert += website;
  insert += "', '";
  insert += password;
  insert += "'); ";

  return insert;
}
