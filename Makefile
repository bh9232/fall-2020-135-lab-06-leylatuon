main: main.o funcs.o caesar.o vigenere.o decrypt.o decode.o
	g++ -o main main.o funcs.o caesar.o vigenere.o decrypt.o decode.o

tests: tests.o funcs.o caesar.o vigenere.o decrypt.o decode.o
	g++ -o tests tests.o funcs.o caesar.o vigenere.o decrypt.o decode.o

funcs.o: funcs.cpp funcs.h

main.o: main.cpp funcs.h caesar.h vigenere.h decrypt.h

caesar.o: caesar.cpp caesar.h

vigenere.o: vigenere.cpp vigenere.h caesar.o

decrypt.o: decrypt.cpp decrypt.h caesar.o vigenere.o

tests.o: tests.cpp doctest.h funcs.h caesar.h vigenere.h decrypt.h decode.h

decode.o: decode.cpp decode.h funcs.o caesar.o decrypt.o

clean:
	rm -f main.o tests.o funcs.o caesar.o vigenere.o decrypt.o decode.o
help:
	@echo  make main : make executable named main
	@echo make tests : make test suite named tests

