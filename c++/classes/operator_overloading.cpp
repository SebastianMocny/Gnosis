/*
 *
 * This is my template for document boilerplate. 
 * Last update to this template is: November 12, 2018
 *
 * TODO: Add licensing info. For example, Apache 2.0
 *
 *
 * Author: Sebastian Mocny
 * Date of file creation: Some time before November 12, 2018
 */

#include <iostream>

class Foo {
	private:
		int val;
	public:
		void set_val(int);
		void operator+(Foo const&);
		int get_val() const { return val; }
};

void Foo::set_val (int x) {
	val = x;
}

void Foo::operator+(Foo const& f) {
	val += f.get_val();
}

int main() {
	Foo a, b;
	a.set_val(1);
	b.set_val(2);
	std::cout << a.get_val() << b.get_val() << std::endl;
	a + b;
	std::cout << a.get_val();
	return 0;
}
