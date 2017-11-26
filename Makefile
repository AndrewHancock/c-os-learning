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

$(OBJDIR)/%.o: $(SRCDIR)/*/%.c | $(OBJDIR)
	$(CC) -c -o $@ $<

$(BINDIR)/copy: $(OBJDIR)/copy.o $(OBJDIR)/err_msg.o| $(BINDIR)
	$(CC) -o $@ $(OBJDIR)/copy.o $(OBJDIR)/err_msg.o