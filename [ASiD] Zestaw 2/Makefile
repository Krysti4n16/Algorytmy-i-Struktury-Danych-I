# Nazwa kompilatora
CXX= g++

# Flagi kompilatora
CXXFLAGS= -Wall -std=c++11

#Mozliwe dodtakowe zmienne
LIBS=

# Pliki obiektowe
OBJECTS= main.o

# Pliki naglowkowe 
HFILES= 

#Plik koncowy
TARGET= main.out

%.o : %.cpp $(HFILES) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

#Uruchomienie programu poleceniem "make run"	
run: $(TARGET)
	./$(TARGET)

# Okreslenie celow sztucznych.
.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core