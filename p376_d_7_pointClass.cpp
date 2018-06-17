//	Philipp Siedler
//	Bjarne Stroustrup's PPP
//	Chapter 10 Drill 7

#include "std_lib_facilities.h"

class Point {
public:
	Point(double _x, double _y);
	void set_pt(double _x, double _y);
	double get_pt_x() { return x; }
	double get_pt_y() { return y; }
private:
	double x;
	double y;
};

Point::Point(double _x, double _y) {
	x = _x;
	y = _y;
}

void Point::set_pt(double _x, double _y) {
	x = _x;
	y = _y;
}

ostream& operator<<(ostream& os, Point& _pt) {
	os << "(" << _pt.get_pt_x() << " ," << _pt.get_pt_y() << ")" << endl;
	return os;
}

bool operator!=(Point& _pt1, Point& _pt2) {
	if (_pt1.get_pt_x() != _pt2.get_pt_x() &&
		_pt1.get_pt_y() != _pt2.get_pt_y()) {
		return true;
	}
	else {
		return false;
	}
}

vector<Point> original_pts;
vector<Point> processed_pts;

void fill_vec_pts(vector<Point>& _pts) {
	while (true) {
		cout << "Enter point pairs in format x,y.\n"
			"To end your input type x" << endl;
		double x, y;
		char comma;
		char check;
		cin >> check;

		if (check == 'x') {
			break;
		}
		else {
			cin.putback(check);
		}

		if (cin >> x >> comma >> y) {
			if (comma != ',') {
				cout << "X and y seperated by comma, not: " << comma << endl;
			}
			else {
				Point pt(x, y);
				_pts.push_back(pt);
			}
		}
		else {
			cin.clear();
			string check1;
			cin >> check1;
			cout << "Invalid value input: " << check1 << endl;
		}
	}
}

void print_pts(vector<Point> _pts) {
	for (int i = 0; i < _pts.size(); i++) {
		cout << _pts[i];
	}
}

void output_original_pts(vector<Point> _pts) {
	string oname = "pts.txt";
	ofstream ost(oname);
	if (!ost) error("can't open output file ", oname);

	cout << "Writing file! " << oname << endl;
	for (int i = 0; i < _pts.size(); i++) {
		ost << _pts[i].get_pt_x() << " " << _pts[i].get_pt_y() << endl;
	}
	ost.close();
}

void input_original_pts(vector<Point>& _pts) {
	string iname = "pts.txt";
	ifstream ist(iname);
	if (!ist) error("can't open input file ", iname);

	double x;
	double y;

	while (ist >> x >> y) {
		Point p(x, y);
		_pts.push_back(p);
	}
}

void compare_pt_vectors(vector<Point>& _pts1, vector<Point>& _pts2) {
	bool check;
	for (int i = 0; i < _pts1.size(); i++) {
		if (_pts1[i] != _pts2[i]) {
			check = false;
		}
		else {
			check = true;
		}
	}
	if (check) {
		cout << "Vectors are the same." << endl;
	}
	else {
		cout << "Vectors are different." << endl;
	}
}

int main()
try
{
	fill_vec_pts(original_pts);
	output_original_pts(original_pts);
	input_original_pts(processed_pts);

	cout << "Original pts: " << endl;
	print_pts(original_pts);

	cout << "Processed pts: " << endl;
	print_pts(processed_pts);

	compare_pt_vectors(original_pts, processed_pts);

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