
all:
	make -C ./server/
	make -C ./client/

re:	fclean all

clean:
	make clean -C ./server/
	make clean -C ./client/

fclean:
	make fclean -C ./client/
	make fclean -C ./server/


