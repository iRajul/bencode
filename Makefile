
CC=/software/gcc/v4.9.2/x86_64-redhat-gnu_rhel5/bin/g++
CFLAGS= -Wall -pedantic -std=c++14 -I./include


SRCDIR = src
INCDIRS = include
AR = ar 

INCLUDES := $(wildcard $(INCDIR)/*.hxx)


OBJDIR := obj
LIBDIR := lib

SOURCES  := $(wildcard $(SRCDIR)/*.cxx)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cxx=$(OBJDIR)/%.o)
MKDIR_P  = mkdir -p


default : objdirectory libbencode.a

objdirectory : 
		test -d $(OBJDIR) || mkdir $(OBJDIR);
		test -d $(LIBDIR) || mkdir $(LIBDIR);
		@echo $(SOURCES)
		@echo $(OBJECTS)

libbencode.a :  	$(OBJECTS)
	@$(AR) rcv $(LIBDIR)/$@ $(OBJDIR)/*.o
	@echo " Builing archive complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cxx
	${MKDIR_P} ${OBJDIR} 
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"




