MYSQL_CONCPP_DIR = /usr/local/mysql-connector-c++
CPPFLAGS = -I $(MYSQL_CONCPP_DIR)/include -L $(MYSQL_CONCPP_DIR)/lib64
LDLIBS = -lmysqlcppconn8
CXX = clang++ -stdlib=libc++
CXXFLAGS = -std=c++11
	# Targets needed to bring the executable up to date

main: main.o password.o database.o
	$(CXX) ${LDLIBS} -o main main.o password.o database.o

# The main.o target can be written more simply
main.o: main.cpp password.h database.h
	$(CXX) $(CXXFLAGS)  ${CPPFLAGS} -c main.cpp

password.o: password.h database.h
	$(CXX) $(CXXFLAGS)  ${CPPFLAGS} -c password.cpp

database.o: database.cpp database.h password.h
	$(CXX) $(CXXFLAGS)  ${CPPFLAGS} -c database.cpp
