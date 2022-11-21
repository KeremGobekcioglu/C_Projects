all: clean compile run

compile: main.c utils.c utils.h
	
	@ gcc main.c utils.c -o a.out

run:

	@./a.out
clean:

	@rm -f customeraccount.txt
	@rm -f a.out

