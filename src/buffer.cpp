#include <iostream>
#include <string>

// Seems impossible to force a buffer overrun
std::string copy(char* buf) {
	char p[20];
	size_t size = strlen(buf) + 1;
	memcpy_s(p, 100, buf, size);
	return p;
}

int main(int argc, char** argv)
{
	auto str = copy(argv[0]);
	std::cout << str << std::endl;
	return 0;
}