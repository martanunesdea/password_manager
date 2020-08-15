/* Header file defining class "password"
 * Project name: Password Encoder
 * Author: Marta Nunes de Abreu
 * Date: 31-07-2020
 */
 #ifndef PASSWORD_H // include guard
 #define PASSWORD_H


#include <iostream>
#include <string>
#include <vector>


class Password_entry{
  public:
    Password_entry();
    ~Password_entry();

    std::string get_password();
    std::string get_website();
    int create_password(void);
    int save_password_entry(void);
    int get_password_entry(void);

  private:
    std::string website_;
    std::string date_;
    std::string password_;
    int id_;
};



#endif
