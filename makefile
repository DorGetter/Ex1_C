
#Ex1_0 the  real one;;
 # $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :


CC          =gcc
CFLAGS = -I.
OBJ         = myBank.o 
DEPSM  =progD 
DEPS     = myBank.h
#The main Execute files:
defualt:   myBank

 myBank:  main.c libMyBankS.a
	$(CC) -Wall $^   -o $@
	
 libMyBankS.a:  myBank.o
	ar -rcs $@ $^


  myBank.o: myBank.c myBank.h
	$(CC) -c -fPIC myBank.c -o $@
	

.PHONY: clean all
 
clean:
	rm *.o *.a  *myBank



















