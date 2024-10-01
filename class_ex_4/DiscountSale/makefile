c_main: sale.o discountsale.o discount_main.o
	clang++ sale.o discountsale.o discount_main.o -o c_main

# Rule to compile
sale.o: sale.h sale.cpp
	clang++ -c sale.cpp

# Rule to compile discountsale.cpp
discountsale.o: discountsale.h sale.h discountsale.cpp
	clang++ -c discountsale.cpp

# Rule to compile discount_main.cpp
discount_main.o: discountsale.h sale.h discount_main.cpp
	clang++ -c discount_main.cpp

# Clean rule to remove object files and the executable
clean: 
	rm *.o c_main