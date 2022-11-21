all: clean compile run

compile: pick3.c util.c util.h
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -o test pick3.c util.c

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./test
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f test
	@rm -f *.o
