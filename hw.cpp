#include <iostream>
#include "Lib.h"
using namespace std;
__interface IDriveable {
public:
	void drive();
	void stop();
	void upSpeed();
	void downSpeed();

};
class Horse : public IDriveable {
	//horse
	//car
	const size_t max_speed;
	size_t current_speed;
	string breed;
	string name;
public:
	Horse(const size_t& speed = 0, const size_t&max_speed=120,const string& breed = "Default", const string& name = "Ramboo") :current_speed(speed),max_speed(max_speed), breed(breed), name(name) {};
	void drive() {
		if (current_speed == 0)
		{
			current_speed = 1;
		}
		cout << "Drive" << endl;
	};
	void stop() {
		current_speed = 0;
		cout << "Stoped" << endl;
	};
	void upSpeed() {
		if (this->current_speed != max_speed)
		{
			cout << "Down speed, now speed : " << current_speed << endl;
			++current_speed;
		}
		else {
			cout << "YOU ALREDY HAVE MAX SPEED" << endl;
		}

	}
	void downSpeed() {
		if (this->current_speed != 0)
		{
			--current_speed;
			cout << "Down speed, now speed : " << current_speed << endl;
		}
		else {
			cout << "To slow down you need to drive a vehicle " << endl;
		}
	}

};
class Car : public IDriveable {
	//horse
	//car
	size_t current_speed;
	const size_t max_speed;
	string name;
public:
	Car(const size_t& speed = 0, const size_t& max_speed = 100, const string& name = "Ramboo") :current_speed(speed), name(name), max_speed(max_speed) {};
	void drive() {
		if (current_speed == 0)
		{
			current_speed = 1;
		}
		cout << "Drive" << endl;
	};
	void stop() {
		current_speed = 0;
		cout << "Stoped" << endl;
	};
	void upSpeed() {
		if (this->current_speed!=max_speed)
		{
			cout << "Up speed, current speed: "<<current_speed << endl;
			++current_speed;
		}
		else {
			cout << "YOU ALREDY HAVE MAX SPEED" << endl;
		}

	}
	void downSpeed() {
		if (this->current_speed!=0)
		{
			--current_speed;
			cout << "Down speed, now speed : " << current_speed << endl;
		}
		else {
			cout << "To slow down you need to drive a vehicle " << endl;
		}
	}
};
class driver
{
public:
	driver(const string& name, IDriveable* vehicle);
	~driver();
	void setVehicle(IDriveable* vehicle) {
		delete this->vehicle;
		this->vehicle = vehicle;
	}
	void testDrive()const {
		vehicle->drive();
		vehicle->upSpeed();
		vehicle->downSpeed();
		vehicle->stop();
	}
	void print()const {
		cout << "Driver name: " << name << endl;
		cout<<"Vehicle type: "<<typeid(*vehicle).name()+6 << endl;
	}
protected:
	string name;
	IDriveable* vehicle;
};

driver::driver(const string& name, IDriveable* vehicle)
	:name(name), vehicle(vehicle)
{

}

driver::~driver()
{
	delete vehicle;
	vehicle = nullptr;
}
int main() {
	IDriveable* x5=new Car(100,290,"BMW X5");
	driver oleksiy("Oleksiy",x5);
	oleksiy.setVehicle(new Car(120, 390, "BMW X6"));
	oleksiy.print();
	oleksiy.testDrive();
	return 0;
}
