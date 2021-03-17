TARGET = bgi2illumina
PREFIX = /usr/local/bin

.PHONY: all clean install uninstall

$(TARGET):
	gcc -o $(TARGET) $(TARGET).c
clean:
	rm -f $(TARGET)
install:
	install $(TARGET) $(PREFIX)
uninstall:
	rm -rf $(PREFIX)/$(TARGET)

all: clean $(TARGET) 
