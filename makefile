default: tokenizer
tokenizer: tokenizer.c
	gcc -Wall -g -o tokenizer tokenizer.c
clean:
	rm tokenizer