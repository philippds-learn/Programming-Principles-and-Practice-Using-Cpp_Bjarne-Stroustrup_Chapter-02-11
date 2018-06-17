//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 5 Try This page 153

#include "std_lib_facilities.h"

int main(){
	if (true) {
		error("Error to be caught");
	}
}
/*
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	keep_window_open();
	return 2;
}
*/

/*Error Message
Unhandled exception at 0x7494A882 in BjarneStroustrup_PrinciplesPractice.exe:
Microsoft C++ exception: std::runtime_error at memory location 0x00CFF6F0.
*/