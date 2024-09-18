testdriveremployee: employee.o salariedemployee.o hourlyemployee.o testdriveremployee.o
	clang++ employee.o salariedemployee.o hourlyemployee.o testdriveremployee.o -o testdriveremployee
employee.o: employee.h employee.cpp
	clang++ -c employee.cpp
salariedemployee.o: salariedemployee.h salariedemployee.cpp
	clang++ -c salariedemployee.cpp
hourlyemployee.o: hourlyemployee.h hourlyemployee.cpp
	clang++ -c hourlyemployee.cpp
testdriveremployee.o: salariedemployee.h hourlyemployee.h testdriveremployee.cpp
	clang++ -c testdriveremployee.cpp
clean: 
	rm *.o testdriveremployee

