# Include configuration
include config.mk

LIB_NAME = pargs
STATIC_LIB = $(OUT_DIR)/$(LIB_NAME).a
SHARED_LIB = $(OUT_DIR)/$(LIB_NAME).so

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

PREFIX = /usr/local
LIB_DIR = $(PREFIX)/lib
INCLUDE_DIR = $(PREFIX)/include

all: $(OUT_DIR) $(STATIC_LIB) $(SHARED_LIB)

$(STATIC_LIB): $(OBJS)
	ar rcs $@ $^

$(SHARED_LIB): $(OBJS)
	$(CC) $(CFLAGS) -shared -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

install: all
	install -d $(DEST_DIR)$(LIB_DIR)
	install -m 644 $(STATIC_LIB) $(DEST_DIR)$(LIB_DIR)
	install -m 644 $(SHARED_LIB) $(DEST_DIR)$(LIB_DIR)
	install -d $(DEST_DIR)$(INCLUDE_DIR)
	install -m 644 *.h $(DEST_DIR)$(INCLUDE_DIR)

uninstall:
	rm -f $(DEST_DIR)$(LIB_DIR)/$(LIB_NAME).a
	rm -f $(DEST_DIR)$(LIB_DIR)/$(LIB_NAME).so
	rm -f $(DEST_DIR)$(INCLUDEDIR)/*.h

clean:
	rm -rf $(OUT_DIR) *.o

.PHONY: all clean install uninstall
