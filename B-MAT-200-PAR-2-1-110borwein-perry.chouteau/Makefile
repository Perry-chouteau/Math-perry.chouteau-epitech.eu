NAME = 110borwein

SOURCES = sources

all: $(NAME)

$(NAME):
	cp $(SOURCES)/main.py $(NAME)
	chmod +x $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: clean all

.PHONY: all clean fclean re
