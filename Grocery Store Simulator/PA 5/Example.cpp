#include "Practice.h"

Example::Example() 
{
	length = 0;
	width = 0;
}

Example::Example(Example &copy)
{
	length = copy.getLength();
	width = copy.getWidth();
}

Example::~Example()
{

}

int Example::getLength() const
{
	return length;
}

int Example::getWidth() const
{
	return width;
}

void Example::setLength(int newLength)
{
	length = newLength;
}

void Example::setWidth(int newWidth)
{
	width = newWidth;
}

int Example::add(int length, int width)
{
	return (length + width);
}