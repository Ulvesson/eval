#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

#include <sys/stat.h>
#include <string.h>

using namespace std;

// Using pointer to temporary memory
static void issue1() {
    stringstream ss;

    ss << "Hello, World!";
    auto msg = ss.str().c_str();
    cout << msg << endl; // Wrapper object used after free
}

// Returning unitialized value
static int issue2(int thing) {
    int result;

    if (thing == 44) {
        return 1;
    }

    return result;
}

// Uninitialized scalar value
static string issue3(double value) {
    stringstream ss;
    ss.precision(numeric_limits<double>::digits10);
    ss << value << " is a nice floating point value.";
    return ss.str();
}

// Unchecked return value from library
static size_t issue4(const string& filename) {
    struct stat st;
    stat(filename.c_str(), &st);
    return st.st_size;
}

// Large stack and more things and stuff, really bad code
static char* issue5(const string& msg) {
    char buf[15000];
    strcpy(buf, msg.data());
    memcpy(buf + 1000, msg.c_str(), 200);

    auto result = new char[2000];
    memcpy(result, buf, 512);
    return result;
}

// Code style can generate issue
static string issue6(const string& text) {
    if (text.size() > 0) {
        auto buf = new char[text.size() + 1];
        strncpy(buf, text.c_str(), text.size());
        return buf;
    }

    return "";
}

// Code style can generate issue - can't reproduce yet :/
static string issue7(const string& text) {
    if (text.size() > 0) {
        auto buf = new char[text.size() + 1];
        strncpy(buf, text.c_str(), text.size());
        string result(buf);
        delete[]buf;
        return result;
    }

    return "";
}

static void issue8(int number) {
    if (number < 0) {
        throw invalid_argument("I don't like negative numbers!");
    }

    cout << "I like this!" << endl;
}

static void unused() {
    cout << "Not called" << endl;
}

int main(int argc, char* argv[]) {
    issue1();
    cout << "issue2 returns: " << issue2(0) << endl;
    cout << issue3(44.1234567890) << endl;
    cout << "issue4 filesize: " << issue4("gurka") << endl;
    cout << "issue5 is a big mess: " << issue5("now we talking!") << endl;
    cout << "issue6 memory leak and more: " << issue6("please show some more bad things.") << endl;
    cout << "issue7 unchecked value: " << issue7("please show some unchecked value.") << endl;
    issue8(-1);
    return 0;
}
