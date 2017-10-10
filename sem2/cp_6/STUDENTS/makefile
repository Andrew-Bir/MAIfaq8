# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -pedantic -ansi -std=c99 -O2 -g -I$(INCDIR)

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lm

# define the executable file 
EXEC=generate
EXECUT=execute

#Root folder code :
CODE := $(shell pwd)

# define the C source files
SRCDIR=$(CODE)/src
# define any directories containing header files other than /usr/include

INCDIR = $(CODE)/include
INCLUDES := $(wildcard (INCDIR)/*.h)
OBJDIR = $(CODE)/obj
EXISTE := $(wildcard $(OBJDIR))

# List of source files :
SRC = $(wildcard $(SRCDIR)/*.c)
# List of object files :

#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJ := $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))
#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY : all

all: $(OBJDIR) $(EXEC) $(EXECUT)
	@echo Simple compiler named $(EXEC) has been compiled
	@echo Simple compiler named $(EXECUT) has been compiled

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(EXEC): $(OBJ) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LIBS)

$(OBJ): $(SRC) $(INCLUDES)
# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< $(CFLAGS) -o $@

$(EXECUT): $(OBJDIR)/student.o $(INCLUDES)
	$(CC) execute.c $(CFLAGS) -o $(EXECUT) $(OBJDIR)/student.o $(LIBS)
	
.PHONY : clean

clean:
	rm -rf *~ 
	rm -rf $(OBJ)
	rm -rf $(OBJDIR)
	rm -f $(EXEC)
	rm -f $(EXECUT)

#makedepend: depend

#depend: $(SRC)
#	$(CC) -MM -I$(INCDIR) $^ >makedepend

#include makedepend
