CC=gcc
OBJDIR=obj

$(OBJDIR): 
	mkdir $(OBJDIR)

program: *.c | $(OBJDIR)
	$(CC) -o program *.c
