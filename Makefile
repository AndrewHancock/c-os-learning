CC     := gcc

SRCDIR :=src
OBJDIR :=obj
BINDIR :=bin

.PHONY: clean
clean:
	rm $(OBJDIR)/*
	rm $(BINDIR)/*

$(OBJDIR): 
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

%.o: $(SRCDIR)/*/%.c | $(OBJDIR)
	$(CC) -c -o $(OBJDIR)/$@ $<

copy: copy.o err_msg.o| $(BINDIR)
	$(CC) -o $(BINDIR)/copy $(OBJDIR)/copy.o $(OBJDIR)/err_msg.o