all: clean compile run

compile: main.c utils.c utils.h
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -c main.c 
	@gcc -c utils.c

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@gcc -o program main.o utils.o
	@echo "================================================================================="
	@./program
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f program
	
