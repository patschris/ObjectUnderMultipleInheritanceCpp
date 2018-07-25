#include <iostream>

using namespace std;
/*
	   A
	   ^^
	  / \
	 /   \
	B    C
	^    ^
	 \  /
	  \/
	  D
*/
class A {
	public:
		int ia;
		
		A() {
			ia = 1;
		}
		
		virtual void foo() {
			cout << "A::foo";
		}
};

class B : public virtual A {
	public:
		int ib;
		
		B() {
			ib = 2;
		}
		
		virtual void bar() {
			cout << "B::bar";
		}
};

class C : public virtual A {
	public:
		int ic;

		C() {
			ic = 3;
		}

		virtual void fun() {
			cout << "C::fun";
		}
};

class D : public B, public C {
	public:
		int id;
		
		D() {
			id = 4;
		}

		virtual void meth() {
			cout << "D::meth";
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
	D d;
	int *base, *vptr;
	/* Printing inheritance type */	
	cout << endl << "\t   A" << endl;
	cout << "\t   ^^" << endl;
	cout << "\t  / \\" << endl;
	cout << "\t /   \\" << endl;
	cout << "\tB    C" << endl;
	cout << "\t^    ^" << endl;
	cout << "\t \\  /" << endl;
	cout << "\t  \\/" << endl;
	cout << "\t  D" << endl << endl;
	/* Printing inheritance information */
	cout << "B is primary parent class for D" << endl;
	cout << "C is parent class for D" << endl;
	cout << "A is parent class for B,C (virtual inheritance)" << endl; 
	cout << "D -> B -> A primary path" << endl;
	cout << "D -> C -> A alternative path" << endl << endl;
	/* Printing object's layout */
	cout << "*pointers and offsets in the vtables are ignored" << endl;
	base = (int*)(&d);
	vptr =  *(int**)(&d);
	cout << "---------------------" << endl;
	cout << "| " << bold_on << "D's object layout" << bold_off << " |" << endl;
	cout << "---------------------" << endl;
	cout << "|" << bold_on << "  Vtable for B,D   " << bold_off << "|" << endl << "|      ";
	((void (*)()) vptr[0])(); // B::bar
	cout << "       |" << endl << "|      ";
	vptr = vptr +2;
	((void (*)()) vptr[0])(); // D::meth
	cout << "      |" << endl << "---------------------" << endl;	
	cout << "|" << bold_on << "     B fields      " << bold_off << "|" << endl;
	base = base+2;
	cout << "|       ib " << *base << "        |" << endl; // B::ib
	cout << "---------------------" << endl;
	cout << "|" << bold_on << "   Vtable for C    " << bold_off << "|" << endl << "|      ";
	base = base+2;
	vptr =  *(int**)base;
	((void (*)()) vptr[0])(); // C::fun
	cout << "       |" << endl << "---------------------" << endl;
	cout << "|" << bold_on << "     C fields      " << bold_off << "|" << endl;
	base = base+2;
	cout << "|       ic " << *base << "        |" << endl; // C::ic
	cout << "---------------------" << endl;
	cout << "|" << bold_on << "     D fields      " << bold_off << "|" << endl;
	base ++;
	cout << "|       id " << *base << "        |" << endl; // D::id
	cout << "---------------------" << endl;
	cout << "|" << bold_on << "   Vtable for A    " << bold_off << "|" << endl << "|      ";
	base ++;
	vptr =  *(int**)base;
	((void (*)()) vptr[0])(); // A::foo
	cout << "       |" << endl << "---------------------" << endl;
	cout << "|" << bold_on << "     A fields      " << bold_off << "|" << endl;
	base = base+2;
	cout << "|       ia " << *base << "        |" << endl; // A::ia
	cout << "---------------------" << endl << endl; 
	/* Printing combined vtable */
	cout << "Compiler uses only one vtable" << endl << "The vtables above are just pointers to the following vtable" << endl;
	cout << "*pointers and offsets in the vtable are ignored" << endl;
	cout << "---------------------" << endl;
	cout << "|" << bold_on << "      Vtable       " << bold_off << "|" << endl;
	cout << "---------------------" << endl << "|      ";
	vptr =  *(int**)(&d);
	((void (*)()) vptr[0])(); // B::bar
	cout << "       |" << endl << "|      ";
	vptr = vptr+2;
	((void (*)()) vptr[0])(); // D::meth
	cout << "      |" << endl << "|      ";
	vptr = vptr+8;
	((void (*)()) vptr[0])(); // C::fun
	cout << "       |" << endl << "|      ";
	vptr = vptr+8;
	((void (*)()) vptr[0])(); // A::foo
	cout << "       |" << endl;
	cout << "---------------------" << endl << endl; 
	/* Printing pointer's size */
	cout << "Size of pointer is " << sizeof(void*) << " bytes" << endl << endl;
	return 0;
}