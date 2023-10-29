# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Nome do arquivo executável
TARGET = $(BIN_DIR)/bintree.exe

# Compilador C
CC = gcc

# Flags de compilação
CFLAGS = -Wall -pedantic -Werror -Wextra

# Arquivos-fonte
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Arquivos de cabeçalho
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)

# Objetos gerados
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(TARGET)

# Regra pra linkagem
$(TARGET): $(OBJECTS)
    $(CC) $(CFLAGS) $(OBJECTS) -o $@

# Regra de compilação para arquivos .c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
