//============================================================================
// Name        : add_data_to_mysql.cpp
// Author      : Tinh H. Nguyen
// Version     :
// Copyright   : Your copyright notice
// Description : Program to work with Mysql server via Mysqlconnector
//============================================================================

#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <stdint.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include <ctime>
#include <unistd.h>
#include <pthread.h>
using namespace std;

void* insertData(void* param){
	char sql_temp_str[1024];
	int* p = (int*) param;
	//start use mysql connector

	try{
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("127.0.0.1", "test", "test@2019");
		/* Connect to the MySQL test database */
		con->setSchema("TEST_MYSQL");
		std::string name = "sinhvien_";
		std::string monhoc = "monhoc_";
		stmt = con->createStatement();
		if(*p == 0){
			/* Create SQL statement */
			for(int i = 0; i < 10; i++){
				memset(sql_temp_str, 0, 1024);
				std::stringstream ss;
				ss << i;
				name += ss.str();
				snprintf(sql_temp_str,
						1024,
						"insert into SINHVIEN (masv,hoten) values(%d,'%s');",\
						i,
						name.c_str());
				stmt->execute(sql_temp_str);
			}
	
			for(int i = 0; i < 10; i++){
				memset(sql_temp_str, 0, 1024);
				std::stringstream ss;
				ss << i;
				monhoc += ss.str();
				snprintf(sql_temp_str,
						1024,
						"insert into MONHOC (mamon,tenmon) values(%d,'%s');",\
						i,
						monhoc.c_str());
				stmt->execute(sql_temp_str);
			}
		}
		uint count = 1;
		int i = *p;
		for(int j = 0; j < 10; j++) {
			for(int k = 0; k < 100000; k++){
				memset(sql_temp_str, 0, 1024);
				std::stringstream ss;
				ss << i;
				int diem = rand() % 10;
				snprintf(sql_temp_str,
						1024,
						"insert into BANGDIEM (masv,mamon,diem,thoigian) values(%d,%d,%d,%d), (%d,%d,%d,%d), (%d,%d,%d,%d), (%d,%d,%d,%d) \
						, (%d,%d,%d,%d),(%d,%d,%d,%d), (%d,%d,%d,%d), (%d,%d,%d,%d), (%d,%d,%d,%d), (%d,%d,%d,%d);",\
						i,j,diem,count,i,j,diem,count+1,i,j,diem,count+2,i,j,diem,count+3,i,j,diem,count+4,i,j,diem,\
						count+5,i,j,diem,count+6,i,j,diem,count+7,i,j,diem,count+8,i,j,diem,count+9));
				count +=  10;
				printf("SQL command: %s count: %d\n",sql_temp_str,count);
				stmt->execute(sql_temp_str);
			}
		}
		delete stmt;
		delete con;
	std::cout<<"Finish add data to DB"<<std::endl;
		return ;

	}
 	catch (sql::SQLException &e) {
	  std::cout << "# ERR: SQLException in " << __FILE__;
	  std::cout << "(" << __FUNCTION__ << ") on line "<< __LINE__ << std::endl;
	  std::cout << "# ERR: " << e.what();
	  std::cout << " (MySQL error code: " << e.getErrorCode();
	  std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;

	  return ;
	}
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	insertData();
	pthread_t thread_arr[10];
	for(int i = 0; i < 10; i++){
		pthread_create(&thread_arr[i],NULL,insertData,&i);
	}
	while(1){
		sleep(1);
	}
	return 0;
}
