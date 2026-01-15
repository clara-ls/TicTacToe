CC = gcc
CFLAGS = -Wall -Werror -Wextra
SOURCES = main.c morpion.c ia_morpion.c display.c alpha_beta.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = morpion

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all