APPNAME=app

all:
	g++ main.cpp -g -I. -o $(APPNAME)

.PHONY: test
test:
	g++ -I. test.cpp -o test
	clear && echo "Running all tests:" && ./test --output=color

clean:
	rm -f $(APPNAME)
	rm -f test