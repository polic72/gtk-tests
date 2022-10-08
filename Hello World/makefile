PROG = gtk-test
OBJS = $(PROG).o

DOC = html

CC = gcc
CFLAGS = $(shell pkg-config --cflags gtk4)
LIBS = $(shell pkg-config --libs gtk4)


all : $(PROG) $(DOC)


$(PROG) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG) $(LIBS)

$(DOC) : Doxyfile *.c
	doxygen

%.o : %.c
	$(CC) $(CFLAGS) -c $< $(LIBS)


clean:
	rm -f $(OBJS) $(PROG)
	rm -rf $(DOC)
