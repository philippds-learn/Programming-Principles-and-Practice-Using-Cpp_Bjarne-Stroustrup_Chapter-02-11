//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 12 Drill 1

#include "std_lib_facilities.h"
#include <FL/Fl.h>
#include <FL/Fl_Box.h>
#include <FL/Fl_Window.h>


int main()
try
{

	keep_window_open();
}
catch (runtime_error e) {
	cout << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cout << "Exiting" << endl;
	keep_window_open();
}

/*
<pre><strong>Output:</strong>

</pre>
*/