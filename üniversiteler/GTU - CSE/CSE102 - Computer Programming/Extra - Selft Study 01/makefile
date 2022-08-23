main:
	gcc tweetsGenerator.c -o tweetsGenerator -Wall -Wextra -Wvla -std=c99
	./tweetsGenerator 15715 10 justdoit_tweets.txt

debug:
	gcc tweetsGenerator.c -o -g tweetsGenerator -Wall -Wextra -Wvla -std=c99
	gdb ./tweetsGenerator 15715 10 justdoit_tweets.txt 100

memory:
#--track-origins=yes -s
	valgrind  ./tweetsGenerator 15715 1 justdoit_tweets.txt