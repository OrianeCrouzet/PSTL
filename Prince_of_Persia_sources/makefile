

CC = gcc                        
CFLAGS = -Wall `sdl2-config --cflags` 
LDFLAGS = `sdl2-config --libs`  
SRC = topctrl.c FrameAdV.c Grafix.c GameBG.c hires.c BGDATA.c EQ.c GameEQ.c HRtables.c Tables.c  
OBJ = $(SRC:.c=.o)               
EXEC = mon_programme           

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)

rebuild: clean all
