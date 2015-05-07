CC= gcc
CFLAGS= -Wall -I.
EXE_NAME=Lotto
FILES= lotto_kone.c
INCLUDE = 

all: $(FILES) $(INCLUDE)
	clear
	$(CC) -o $(EXE_NAME) $(FILES)  $(CFLAGS)

clean:
	rm -f *.o
	rm -f *~
	rm -f $(EXE_NAME)
	
run:
	./$(EXE_NAME)

rebuild: clean all

build: clean all run
