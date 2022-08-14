SRCDIR := src
OBJDIR := obj

SRC := main.cpp settings.cpp particles.cpp render.cpp
OBJ := $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

CXX := g++
CXXFLAGS := -lsfml-graphics -lsfml-window -lsfml-system
TARGET := particles

all: out run

run:
	./$(TARGET)

out: $(OBJDIR) $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(CXXFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $^ -o  $@

$(OBJDIR):
	mkdir $@

clean:
	rm -rf $(OBJDIR)

