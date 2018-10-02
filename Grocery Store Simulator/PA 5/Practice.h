#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Example
{
public:
	Example();
	Example(Example &copy);
	~Example();

	int getLength() const;
	int getWidth() const;

	void setLength(int newLength);
	void setWidth(int newWidth);

	int add(int length, int width);
private:
	int length;
	int width;
};