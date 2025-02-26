APPNAME=app

all:
	g++ main.cpp -g -o $(APPNAME)

.PHONY: test
test:
	g++ -Wall test.cpp -o test
	clear && echo "Running all tests:" && ./test --output=color

clean:
	rm -f $(APPNAME)
	rm -f test