# Source: http://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/
CC := g++
SRCDIR := src
BUILDDIR := build
BINDIR := bin
TARGET := $(BINDIR)/TheLastTooFast

SRCEXT := cpp
SOURCES:=$(wildcard $(SRCDIR)/*.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
FILTERED_OBJECTS := include$(filter-out $(BUILDDIR)/TheLastTooFast.o, $(OBJECTS))
# Descomente essa linha para ativar o modo DEBUG
CFLAGS := -Wall -std=c++11 #-g -DDEBUG=1
LIB := -L/usr/lib -lallegro_dialog -lallegro_image -lallegro_memfile -lallegro_primitives -lallegro_acodec -lallegro_audio -lallegro_color -lallegro_main -lallegro_physfs -lallegro_ttf -lallegro_font -lallegro -lphysfs
INC := -I include -I/usr/include/allegro5 -I/usr/include/physfs

$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) $(TARGET)"; $(RM) $(TARGET)

.PHONY: clean
