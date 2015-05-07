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

run2:
	./$(EXE_NAME) 10
	
rebuild: clean all

build: clean all run

build2: clean all run2
