CC = clang
LIBS = -luuid
CFLAGS = -pedantic -Wsystem-headers -Wall -Wextra -pedantic-errors -Werror

OBJS = banco.c cliente.c
EXE = banco

all:
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE) $(LIBS)

clean:
	rm -rf $(EXE)

run:
	./$(EXE)

.PHONY: all clean run
