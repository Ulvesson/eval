#include <iostream>
#include <string>

std::string copy(char *buf) {
	char p[20];
	auto size = strlen(buf);
	memcpy(p, buf, size);
	return p;
}

int main(int argc, char** argv)
{
	auto str = copy(argv[0]);
	std::cout << str << std::endl;
	return 0;
}