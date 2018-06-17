//	Philipp Siedler
//	Bjarne Stroustrup's PP
//	Chapter 7 Exercise 8

/*
	Simple calculator

	Revision history:
		
		Revised by Philipp Siedler May 2017
		Revised by Bjarne Stroustrup November 2013
		Revised by Bjarne Stroustrup May 2007
		Revised by Bjarne Stroustrup August 2006
		Revised by Bjarne Stroustrup August 2004
		Originally written by Bjarne Stroustrup
			(bs@cs.tamu.edu) Spring 2004

	This program implements a basic expression calculator.
	Input from cin; output to cout;
	The grammar for input is:
	
	Calculation:
		Statement
		Print
		Quit
		Help
		Calculation Statement

	Statement:
		Declaration
		Expression
	
	Declaration:
		"let" Name "=" Expression
		"const" name "=" Expression

	Name:
		letter
		letter Sequence
		Sequence:
		letter
		digit
		"_"
		letter Sequence
		digit Sequence
		"_" Sequence

	Print:
		";" or '\n'
	
	Quit:
		"quit"
	
	Help
		"help" or "Help"

	Expression:
		Term
		Expression + Term
		Expression - Term

	Term:
		Primary
		Term * Primary
		Term / Primary
		Term % Primary

	Primary:
		Number
		"(" Expression ")"
		"-" Primary
		"+" Primary
		"sqrt(" Expression ")"
		"pow(" Expression "," Integer ")"
		Name
		Name "=" Expression
	
	Number:
		floating-point-literal

	Input comes from cin through the Token_stream called ts.

*/