SOURCE=aes.cpp main.cpp aesoptions.cpp
HEADERS=aes.h aesoptions.h
MYPROGRAM=paes
MYINCLUDES=.

MYLIBRARIES=openmp
CC=g++

all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE) $(HEADERS)
	$(CC) -I$(MYINCLUDES) $(SOURCE) -o$(MYPROGRAM) -f$(MYLIBRARIES)

clean:
	rm -f $(MYPROGRAM)
