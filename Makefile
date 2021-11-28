target=C_DataStructure_test.exe
src=C_DataStructure_test.o 

$(target) : $(src)
	gcc -o $@ $^
%.o : %.c
	gcc -c -o $@ $^

clean: 
	rm $(target) $(src)