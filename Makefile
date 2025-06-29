# Nombre del ejecutable
TARGET = app

# Compilador
CXX = g++

# Archivo principal (en el mismo directorio del Makefile)
MAIN = MyApp.cpp

# Archivos fuente del proyecto en src/
SRC = $(wildcard src/*.cpp)

# Archivos fuente de ImGui
IMGUI_DIR = dependencies/imgui
IMGUI_SRC = \
    $(IMGUI_DIR)/imgui.cpp \
    $(IMGUI_DIR)/imgui_draw.cpp \
    $(IMGUI_DIR)/imgui_tables.cpp \
    $(IMGUI_DIR)/imgui_widgets.cpp \
	$(IMGUI_DIR)/imgui_demo.cpp \
    $(IMGUI_DIR)/backends/imgui_impl_glfw.cpp \
    $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp \
# Archivos de Implot
IMPLOT_DIR = dependencies/implot
IMPLOT_SRC = \
    $(IMPLOT_DIR)/implot.cpp \
    $(IMPLOT_DIR)/implot_items.cpp \
	$(IMPLOT_DIR)/implot_demo.cpp \

GLM_DIR = dependencies/glm
# Directorios de inclusión
INCLUDES = -Iinclude -I$(IMGUI_DIR) -I$(IMGUI_DIR)/backends -I$(IMPLOT_DIR) -Iinclude/classes -Iinclude/Interfaces -Iinclude/classes/EntityAtribs -Idependencies -Iextras

# Flags del compilador
CXXFLAGS = -Wall -std=c++17 $(INCLUDES)

# Librerías a enlazar
LIBS = -lGLEW -lglfw -lGL -lassimp

# Carpeta de salida
BIN = bin
OUT = $(BIN)/$(TARGET)

# Regla principal
all: $(BIN) $(OUT)

# Compilación
$(OUT): $(MAIN) $(SRC) $(IMGUI_SRC) $(IMPLOT_SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

# Crear el directorio bin si no existe
$(BIN):
	mkdir -p $(BIN)

# Limpiar bin
clean:
	rm -rf $(BIN)

.PHONY: all clean
