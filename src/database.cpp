#include <iostream>
#include "database.h"
#include <mysqlx/xdevapi.h>

using namespace ::mysqlx;

int create_connection(void)
{
try {

#warning change pwd
  const char   *url ="mysqlx://root:pwd@127.0.0.1";

  std::cout << "Creating session on " << url
       << " ..." << std::endl;

  Session sess(url);

  std::cout <<"Session accepted, creating collection..." <<std::endl;

  Schema sch= sess.getSchema("password_manager");

  sess.sql("USE password_manager").execute();
  // sess.sql("CREATE TABLE password_table id INTEGER, account VARCHAR(20), password VARCHAR(50), date_created DATE);");

  std::string account_name = "amazon";
  std::string password = "seriously_random_password";
  std::string formatted_date = "2020-07-13";

  std::string insert = "INSERT INTO password_table (account, password, date_created) values ('";
  insert += "amazon";
  insert += "', '";
  insert += password;
  insert += "' , '";
  insert += formatted_date;
  insert += "'); ";
  sess.sql(insert).execute();
  std::cout <<"adding to database..."<< std::endl;


  RowResult res = sess.sql("SELECT account, password from password_table").execute();

  Row row;
  while ((row = res.fetchOne())) {
    std::cout << "Account: " << row[0] << "\t Password: " << row[1] << std::endl;
  }

  std::cout <<"Done!" << std::endl;
  }

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
