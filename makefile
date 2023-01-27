compiler        = g++
files       = vigenere.cpp caesar2.cpp caesar.cpp basicencrypt.cpp encrypt.cpp main.cpp

all: compile

compile: $(files)
	$(compiler) $(files) 

clean:
	rm -f a.out

exe:
	./a.out

