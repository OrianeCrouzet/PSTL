

CC = gcc                        
CFLAGS = -Wall `sdl2-config --cflags` 
LDFLAGS = `sdl2-config --libs`  
SRC = topctrl.c frameadv_2.c grafix.c gamebg.c hires.c bgdata.c eq.c gameeq.c hrtables.c tables.c  
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
