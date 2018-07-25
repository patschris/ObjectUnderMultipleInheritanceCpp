#include <iostream>

using namespace std;
/*
	B    C
	^    ^
	 \  /
	  \/
	  A
*/
class B {
	public:
		int ib;

		B(int i=0) {
			ib = i;
		}
		
		void fun() {
			cout << "B::fun" << endl;
		}
		
		virtual void methB() {
			cout << "B::methB";
		}
};

class C {
	public:
		int ic;

		C(int i=0) {
			ic = i;
		}
		
		void fun() {
			cout << "C::fun" << endl;
		}

		virtual void methC() {
			cout << "C::methC";
		}
};

class A : public B, public C {
	public:
		int ia;

		A(int i=0): B(i+1), C(i+2) {	
			ia = i;
		}

		void fun() {
			cout << "A::fun" << endl;
		}

		virtual void methB() {

			cout << "A::methB"; 
		}

		virtual void methC() {
			cout << "A::methC"; 
		}
};

/* https://stackoverflow.com/questions/29997096/bold-output-in-c */
ostream& bold_on(ostream& os) {
    return os << "\e[1m";
}

ostream& bold_off(ostream& os) {
    return os << "\e[0m";
}

int main(void) {
	A a(7);
	int *base, *vptr;
	/* Printing inheritance type */	
	cout << endl << "\tB    C" << endl;
	cout << "\t^    ^" << endl;
	cout << "\t \\  /" << endl;
	cout << "\t  \\/" << endl;
	cout << "\t  A" << endl;
	/* Printing inheritance information */
	cout << endl << "B is primary parent class for A" << endl;
	cout << "C is parent class for A" << endl;
	cout << "A inherites from B,C" << endl << endl;
	/* Printing object's layout */
	cout << "*pointers and offsets in the vtables are ignored" << endl;
	base = (int*)(&a);
	vptr =  *(int**)(&a);
	cout << "---------------------" << endl;
	cout << "| " << bold_on << "A's object layout" << bold_off << " |" << endl;
	cout << "---------------------" << endl;
	cout << "|" << bold_on << "  Vtable for A,B   " << bold_off << "|" << endl << "|     ";
	((void (*)()) vptr[0])(); // call A::methB
	cout << "      |" << endl;
	vptr =  vptr+2;
	cout << "|     ";
	((void (*)()) vptr[0])(); // call A::methC
	cout << "      |" << endl << "---------------------" << endl;
	cout << "|" << bold_on << "     B fields      " << bold_off << "|" << endl;
	base = base+2;
	cout << "|       ib " << *base << "        |" << endl; // B::ib
	cout << "---------------------" << endl;
	cout << "|" << bold_on << "   Vtable for C    " << bold_off << "|" << endl << "|     ";
	base = base+2;
	vptr =  *(int**)base; // A::methC
	((void (*)()) vptr[0])();
	cout << "      |" << endl << "---------------------" << endl;
	cout << "|" << bold_on << "     C fields      " << bold_off << "|" << endl;
	base = base+2;
	cout << "|       ic " << *base << "        |" << endl; // C::ic
	cout << "---------------------" << endl;
	cout << "|" << bold_on << "     A fields      " << bold_off << "|" << endl;
	base ++;
	cout << "|       ia " << *base << "        |" << endl; // A::ia
	cout << "---------------------" << endl << endl;
	/* Printing combined vtable */
	base = (int*)(&a);
	vptr =  *(int**)(&a);
	cout << "Compiler uses only one vtable" << endl << "The vtables above are just pointers to the following vtable" << endl;
	cout << "*pointers and offsets in the vtable are ignored" << endl;
	cout << "---------------------" << endl;
	cout << "|" << bold_on << "      Vtable       " << bold_off << "|" << endl;
	cout << "---------------------" << endl << "|     ";
	((void (*)()) vptr[0])(); // A::methB
	cout << "      |" << endl << "|     ";
	vptr = vptr+2;
	((void (*)()) vptr[0])(); // A::methC
	cout << "      |" << endl << "|     ";
	vptr = vptr+6;
	((void (*)()) vptr[0])(); // A::methC
	cout << "      |" << endl;
	cout << "---------------------" << endl << endl;
	/* Printing pointer's size */
	cout << "Size of pointer is " << sizeof(void*) << " bytes" << endl << endl;
	/* Casting objects and test non-virtual functuins */
	cout << "Cast test" << endl << "Calling a non-virtual function fun in an A object" << endl;
	cout << "A object    --> ";
	a.fun(); // A::fun
	cout << "Cast A to B --> ";
	((B)a).fun(); // B::fun
	cout << "Cast A to C --> ";
	((C)a).fun(); // C::fun
	return 0;
}