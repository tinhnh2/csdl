1. How to add data to mysql server
- Install mysql server
- Install mysql-cpp-connector
- Build: g++ -o a.out -lmysqlconn
- Run: ./a.out

2. How to add data to mongodb
- Install mongodb using rpm package
- Install mongodb shell using rpm package
- Connect to mongodb server:
	> mongo 127.0.0.1
	> use test_mongo
- Run on other command line to add data:
	> mongo 172.0.0.1/test_mongo querry.js