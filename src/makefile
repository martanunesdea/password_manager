MYSQL_CONCPP_DIR = /usr/local/mysql-connector-c++
CPPFLAGS = -I $(MYSQL_CONCPP_DIR)/include -L $(MYSQL_CONCPP_DIR)/lib64
LDLIBS = -lmysqlcppconn8
CXX = clang++
CXXFLAGS = -std=c++11
CC = clang++                        # compiler to use

SRCS := $(wildcard *.cpp)
BINS := $(SRCS:%.cpp=%)

all: main main.o password.o database.o

main: main.o
	@echo "Checking.."
	${CC} main.o password.o database.o -o main

main.o: main.cpp
	@echo "Creating object.."
	${CC} -std=c++11 -c main.cpp

password.o: password.cpp
	@echo "Creating object.."
	${CC} -std=c++11 -c password.cpp

database.o: database.cpp
	@echo "Creating object.."
	${CC} -std=c++11 -c database.cpp
