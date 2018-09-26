# Object's Layout Under Multiple Inheritance in C++

The purpose of this program is to show the object's layout under multiple inheritance. Compile with the flag -fdump-class-hierarchy to produce the file that gives information about the class hierarchy and the vtables. We examine two categories:

- **Multiple Inheritance**

Check the folder [Multiple inheritance](https://github.com/patschris/ObjectUnderMultipleInheritanceCpp/tree/master/Multiple%20inheritance)\
![ObjectMultipleInheritance](https://github.com/patschris/ObjectUnderMultipleInheritanceCpp/blob/master/ObjectUnderMultipleInheritance.PNG)\
The corresponding vtable's scheme that is produced by the program is
![VtableMultipleInheritance](https://github.com/patschris/ObjectUnderMultipleInheritanceCpp/blob/master/VtableMultipleInheritance.png)




- **Multiple Virtual Inheritance**

Check the folder [Multiple virtual inheritance](https://github.com/patschris/ObjectUnderMultipleInheritanceCpp/tree/master/Multiple%20virtual%20inheritance)\
![ObjectMultipleVirtualInheritance](https://github.com/patschris/ObjectUnderMultipleInheritanceCpp/blob/master/ObjectUnderVirtualInheritance.PNG)\
The corresponding vtable's scheme that is produced by the program is\
![VtableMultipleInheritance](https://github.com/patschris/ObjectUnderMultipleInheritanceCpp/blob/master/VtableMultipleVirtualInheritance.png)

Contains makefile in each folder. Use `make` to compile, `make run` to execute the program and `make clean` to remove the object files and the executable.
 
Written in C++, Ubuntu 16.04.3 LTS.

**References** \
[1] http://kaisar-haque.blogspot.gr/2008/07/c-accessing-virtual-table.html \
[2] https://stackoverflow.com/questions/6258559/what-is-the-vtt-for-a-class
