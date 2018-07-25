CC		= g++
CFLAGS	= -w -fdump-class-hierarchy
EXEC 	= multipleVirtualInheritance
SRCS 	= multipleVirtualInheritance.cpp
CLASS 	= multipleVirtualInheritance.cpp.002t.class
REM		= rm -f

all:
	$(CC) $(CFLAGS) -o $(EXEC) $(SRCS)

clean:
	$(REM) $(EXEC) $(CLASS)

run:
	./$(EXEC)
