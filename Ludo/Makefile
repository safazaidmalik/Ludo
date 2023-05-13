CXXFLAGS =	-g3 -Wall -fmessage-length=0 #-Werror

OBJS =		 util.o main.o Shape.o Rectangle.o Circle.o Triangle.o RoundRectangle.o Line.o Board.o Player.o BoardSections.o Coordinates.o

LIBS = -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib -L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lglut -lGLU -lGL -lX11 -lfreeimage -pthread



TARGET =	main


$(TARGET):	$(OBJS) 
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
