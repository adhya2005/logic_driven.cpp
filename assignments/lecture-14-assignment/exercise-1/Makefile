APPNAME=app

all:
	g++ main.cpp -g -I. -o $(APPNAME)

.PHONY: test
test:
	g++ -Wall -I. test.cpp -o test
	clear && echo "Running all tests:" && ./test --output=color

.PHONY: pull
pull:
ifeq ($(shell git rev-parse --is-inside-work-tree 2>/dev/null),true)
	@git reset --hard
	@git clean -fdx
	@git pull --ff-only
else
	@echo "No git repository found in the current directory"
endif

clean:
	rm -f $(APPNAME)
	rm -f test