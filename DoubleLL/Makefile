PROJEC=main

CC=gcc

C_SOURCE=$(wildcard *.c)

H_SOURCE=$(wildcard *.h)

OBJ=$(C_SOURCE:.c=.o)


all: $(PROJEC)
	./$<  

$(PROJEC): $(OBJ)
	gcc $^ -o $@

$(OBJ): $(C_SOURCE)
	$(CC) -c $^ 

clean: 
	rm $(PROJEC) $(OBJ)  	

git: 
	git add $(C_SOURCE) $(H_SOURCE) Makefile 
	git commit -m "$(cmt)"
	git push -u origin
