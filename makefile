#makefile for lab 2a pass off cases
NUM:=2
buckets:=80 100
numbers_80:=0 1 2 3 4 5 6 7
numbers_100:=0 
tests:=Project$(NUM)aPassOffCases
project:=Datalog Parser

.SILENT: all $(buckets)

all: $(buckets)
	@rm $(tests)/out.txt

$(buckets):
	echo "Bucket $@"; \
	for number in ${numbers_$@} ; \
	do \
		echo "Running input $$number" ; \
		./project$(NUM) $(tests)/$(NUM)-$@/input$$number.txt > $(tests)/out.txt ; \
		diff -w $(tests)/$(NUM)-$@/answer$$number.txt $(tests)/out.txt || (echo "diff failed on test $$number \n") ; \
	done \

compile:
	g++ -Wall -Werror -std=c++17 -g *.cpp -o project$(NUM)

quick:
	g++ *.cpp -o project$(NUM)

mine: quick
	make