# Password manager

This is a C++ program to run from the command line to generate random passwords. It will save them into a MySQL schema if the address of the website is provided. 

The program is split into three parts:

A. Main file: runs the command line menu. The options given to the user are to: create a random password, to retrieve a password from a given website, or to list all passwords. 

B. Password file: generates the password, relays to the Database file if the password is to be saved or retrieved from persistent storage.

C. Database file: connects to a MySQL schema to either store or retrieve passwords.
