#include <iostream>
#include <mysqlx/xdevapi.h>

using namespace ::mysqlx;


int main(int argc, const char* argv[])
try {

#warning change pwd
  const char   *url = (argc > 1 ? argv[1] : "mysqlx://root:pwd@127.0.0.1");

  std::cout << "Creating session on " << url
       << " ..." << std::endl;

  Session sess(url);

  std::cout <<"Session accepted, creating collection..." <<std::endl;

  Schema sch= sess.getSchema("password_manager");

  sess.sql("USE password_manager").execute();
  // sess.sql("CREATE TABLE password_table id INTEGER, account VARCHAR(20), password VARCHAR(50), date_created DATE);");

  sess.sql("INSERT INTO password_table (account, password, date_created) VALUES ('dummy2', 'abcdef2', '2020-07-11') ").execute();
  std::cout <<"adding to database..."<< std::endl;


  RowResult res = sess.sql("SELECT account, password from password_table").execute();

  Row row;
  while ((row = res.fetchOne())) {
  std::cout << "Account: " << row[0] << std::endl;
  std::cout << " Password: " << row[1] << std::endl;
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
