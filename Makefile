# Nombre del archivo fuente (sin extensión)
SOURCE_FILE = $(file)

# Nombre del ejecutable
TARGET = bin/$(SOURCE_FILE)

# Compilador
CC = g++

# Opciones de compilación
CFLAGS = -Wall -g -O2

.PHONY: all run debug clean

# Regla por defecto: compilar el programa
all: $(TARGET)

# Regla para compilar el programa
$(TARGET): src/$(SOURCE_FILE).cpp
	@echo "Compilando"
	@$(CC) $(CFLAGS) $< -o $@
	@echo "Compilacion terminada"
	@echo ""

# Regla para ejecutar el programa
run: $(TARGET)
	@echo "Ejecutando"
	@echo ""
	@./$(TARGET)
# Regla para debugear el programa
debug: $(TARGET)
	@gdb ./$(TARGET)
# Regla para eliminar el ejecutable
clean:
	@rm -f $(TARGET)
#Regla para eliminar el codigo y el ejecutable
remove:
	@rm -f $(TARGET)
	@rm -f src/$(file).cpp