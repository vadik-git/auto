#include<iostream>
#include<list>
#include<string>
#include<cctype>
#include"Zoo.h"
using namespace std;


class BadLogin :public exception {
private:
public:
	BadLogin(const string &msg):exception (msg.c_str()) {

	}


};
class ManySymbol :public exception {
private:
public:
	ManySymbol(const string &msg) :exception(msg.c_str()) {
	}


};
class IncorectLogin :public exception {
public:
	IncorectLogin(const string &msg):exception(msg.c_str()){}
};
class IncorectPassw :public exception {
public:
	IncorectPassw(const string &msg) :exception(msg.c_str()) {}
};
class BadPassw :public exception {
public:
	BadPassw(const string &msg) :exception(msg.c_str()) {}
};
class BadPassw1 :public exception {
public:
	BadPassw1(const string &msg) :exception(msg.c_str()) {}
};
struct Login {
	string login;
	string password;
};
class Registration {
	list<Login>listLogin;
	Login logins;

	void chekLogin() {
		for (Login log : listLogin) {
			if (logins.login == log.login) {
				throw BadLogin("This login is already there");//cout << "EROOR LOG" << endl;
			}
		}
	}
	void symbol() {

			if (logins.password.size()>=8) {
				throw ManySymbol("your password many sumbol");
			}
	}
	void incorectLogin() {
		for (Login log : listLogin) {
			if (logins.login != log.login) {
				throw IncorectLogin("INCORECT LOGIN");
			}
		}
	}
	void incorectPassw() {
		for (Login log : listLogin) {
			if (logins.password != log.password) {
				throw IncorectPassw("INCORECT PASSWORD");
			}
		}
	}
	void badPasswd() {
		for (int i = 0; i < logins.login.length(); i++) {
			if (logins.password[i] >= 'A' && logins.password[i] <= 'Z') {
				throw BadPassw("YOUR PASSWORD BIG LITERS");
			}
		}
	}
	void badPasswd1() {
		for (int i = 0; i < logins.login.length(); i++) {
			if (logins.password[i] >= '0' && logins.password[i] <= '9') {
				throw BadPassw1("YOUR PASSWORD Numbers");
			}
		}
	}

public:
	void registration() {

		cout << "Enter login" << endl;
		cin >> logins.login;
		try {
			chekLogin();
		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return;
		}
		cout << "Enter password" << endl;
		cin >> logins.password;
		try {
			symbol();

		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return;
		}
		try {
			badPasswd();

		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return;
		}
		try {
			badPasswd1();

		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return;
		}
	
		listLogin.push_back(logins);
	}
	void autorization() {
		cout << "Enter login" << endl;
		cin >> logins.login;
		try {
			incorectLogin();
		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return;
		}
		cout << "Enter password" << endl;
		cin >> logins.password;
		try {
			incorectPassw();
		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return;
		}
		for (Login log : listLogin) {
			if (logins.login == log.login && logins.password == log.password) {
				cout << "HELLO WELCOME TO MY WORLD" << endl;
			}
		}
		
	}
	void watch() {
		for (Login log : listLogin) {
			cout << "LOGIN >> " << log.login << endl;
			cout << "PASSWORD >>" << log.password << endl;
		}
	}
};














class MaxSpeed:public exception {
public:
	MaxSpeed(const string &msg) :exception(msg.c_str()) {}
};
class IncorectNumb :public exception {
public:
	IncorectNumb(const string &msg) :exception(msg.c_str()) {}
};
class BadSpeed :public exception {
public:
	BadSpeed(const string &msg) :exception(msg.c_str()) {}
};

struct Auto {

	string numberAuto;
	int maxSpeed;
	int speed = 0;
};
class AddAuto :public Auto {
	list<Auto>listauto;
	Auto a;
public:
	void addCar() {
		cout << "Enter number auto" << endl;
		cin >> a.numberAuto;
		try {
			
				if (a.numberAuto.size()<8) {
					throw IncorectNumb("Bad numb");
					return;
				}
				
			
		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return;
		}
		cout << "enter max speed auto" << endl;
		cin >> a.maxSpeed;
		cout << "enter speed auto" << endl;
		cin >> a.speed;
		try {
			if (a.speed > a.maxSpeed) {
				throw BadSpeed("your speeed big max speed");
				return;
			}
		}
		catch (exception&ex) {
			cout << ex.what() << endl;
		}
		
	}
	void print() {
		cout << "NUMBER AUTO >> " <<a.numberAuto << endl;
		cout << "MAX SPEED AUTO >> " << a.maxSpeed << endl;
		cout << "SPEED AUTO >> " << a.speed << endl;
	}

	int addSpeed(int b = 5) {
		cout << "Enter speed add" << endl;
		cin >> b;
		try {
			a.speed += b;
			if (a.speed >= a.maxSpeed) {
				a.speed -= b;
				throw MaxSpeed("Your speeed max");
				
				return 0;
			}
		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return 0;
		}
		
	}
	int subtractSpeed(int b = 5) {
		cout << "Enter subtract speed" << endl;
		cin >> b;
		return a.speed -= b;
	}

};
struct Book {
	string name;
	string year;
};

using namespace MyAnimal;

int main() {
	

	AddAuto a1;

	int a;
	do {
		cout << "select action" << endl;
		cin >> a;
		switch (a) {
		case 1:
			a1.addCar();
			break;
		case 2:
			a1.addSpeed();
			break;
		case 3:
			a1.print();
			break;
		case 4:
			a1.subtractSpeed();
			break;
		case 5:
			return 0;
			break;

		}


	} while (a!= 5);

	/*Registration reg;
	Login logins;
	int action;  
	do {
		cout << "1.REGISTRATION " << endl;
		cout << "2.WATCH LOGIN AND PASSWD" << endl;
		cout << "3.AUTORIZATION" << endl;
		cin >> action;
		switch (action) {
		case 1:
			reg.registration();
		
			break;
		case 2:
			reg.watch();
			break;
		case 3:
			reg.autorization();
			break;
		case 0:
			break;
		}
		
	} while (action != 0);*/
	system("pause");
	return 0;
}