CC=gcc
CFLAGS=-I./include -O2 -Wall #-Wextra -Werror
#LINK=  -mwindows -lcomctl32

OBJ_CMS=\
src/main.o

OUT_DIR=build

out_dir:
	mkdir -p $(OUT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

cms: $(OBJ_CMS) out_dir
	#$(CC) $(OBJ_TM) $(LINK) $(CFLAGS) -o $(OUT_DIR)/$@
	$(CC) $(OBJ_CMS) $(CFLAGS) -o $(OUT_DIR)/$@
	./build/cms

.PHONY:
clear:
	rm $(OBJ_CMS) $(OUT_DIR)/cms
