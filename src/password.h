/* Header file defining class "password"
 * Project name: Password Encoder
 * Author: Marta Nunes de Abreu
 * Date: 31-07-2020
 */
#include <iostream>
#include <string>
#include <vector>


class Password{
  public:
    Password();
    ~Password();

    void add_password_entry(std::string , std::string , std::string);
    std::string get_password(int key);
    void save_password_entry(Password*);
  // get_password();
  // set_password();
  // list_saved_passwords();
  private:
    std::string website_;
    std::string date_;
    std::string password_;
    int id_;
};
