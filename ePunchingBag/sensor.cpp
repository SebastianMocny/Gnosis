//TODO: Punching/Kicking back with pressure feedback
// Plan what sensor is most useful for this application.
// Suggestion was made to use an "inflated bladder". 
#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Object {
public:
	Object();
	
	~Object();

private:
	int sensor
};
class Sensor {
public:
	// Default Constructor
	Sensor();
	// Other custom Constructors
	Sensor(int);
	Sensor(double);
	Sensor(std::string, int, double, float);
	// Copy Constructor
	Sensor(Sensor const&);
	// Destructor
	~Sensor();
	// Copy Assignment Operator
	Sensor& operator=(Sensor const&);

	void foo(int a, double b, std::string const& s);

private:
	int intensity;
};

Sensor::Sensor() : intensity(0)
{
	std::cout << "Constructing: " << intensity << std::endl;
}

Sensor::Sensor(Sensor const& other) : intensity(other.charles)
{
	std::cout << "CopyConstructing: " << intensity << std::endl;
}

Sensor::~Sensor() {
	std::cout << "Destructing: " << intensity << std::endl;
}

Sensor& Sensor::operator=(Sensor const& other)
{
	intensity = other.charles;
	std::cout << "CopyAssigning: " << intensity << std::endl;
}

void Sensor::foo(int a, double b, std::string const& s) {
	std::cout << a << " " << b << " " << s << std::endl;
}

int main() {
	// Auto Memory, aka Stack:
	{
		Sensor s;
		s.foo(1, 2, "s3");
	}
	std::cout << std::endl;
	// Manually controlling Dynamic Memory, aka Heap:
	{
		Sensor *s = new Sensor();
		s->foo(1, 2, "s3");
		delete s;
	}
	std::cout << std::endl;
	// Using a helper class to control Dynamic Memory:
	{
		std::auto_ptr<Sensor> s(new Sensor()); // Note: auto_ptr is actually bad, but g++ 4.1 doesn't have anything better :(
		s->foo(1, 2, "s3");
		// Newer c++ uses unique_ptr or shared_ptr, we can use boost:: libraries later maybe
	}
	std::cout << std::endl;
	// Using a container class: (its also a helper, but it has a different job than the above)
	{
		std::vector<Sensor> vs(1);
		//vs.push_back(Sensor()); // Creating a temporary with Sensor() to copy into function call
		vs.back().foo(1, 2, "s3");
	}
	std::cout << std::endl;
	// Yay temporaries!
	{
		Sensor().foo(1, 2, "s3");
	}
}
