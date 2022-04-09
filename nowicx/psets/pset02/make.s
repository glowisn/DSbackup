# On my honor, I pledge that I have neither received nor provided improper assistance in the
# completion of this assignment.
# Signed: _Yechan Jung_ Student Number: __21700663___

# pset02 : build a static library
# make.s - making libsort.a in nowic/lib

CC = g++
CCFLAGS = -Wall
LDFLAGS = -L$(LIBDIR)
LIBDIR = ../../lib
INCDIR = ../../include

SRCS = quicksort.cpp bubble.cpp insertion.cpp selection.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
TARGET = libsort.a

$(TARGET) : $(OBJS)
	ar cru $@ $^
	ranlib $@

$(OBJS) : %.o: %.cpp
	$(CC) -c $(CCFLAGS) $< -o $@
	$(CC) -MM -MF $*.d $<
-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS) #(TARGET)
