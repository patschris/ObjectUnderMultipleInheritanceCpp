CC		= g++
CFLAGS	= -w -fdump-class-hierarchy
EXEC 	= multipleInheritance
SRCS 	= multipleInheritance.cpp
CLASS 	= multipleInheritance.cpp.002t.class
REM		= rm -f

all:
	$(CC) $(CFLAGS) -o $(EXEC) $(SRCS)

clean:
	$(REM) $(EXEC) $(CLASS)

run:
	./$(EXEC)
