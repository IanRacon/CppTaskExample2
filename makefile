MAIN=lab09
SRC=UniquePointer
SRC1=Pointer
#SRC2=foreach
FLAGS=-g -c -Wall
CXX=g++
$(MAIN):$(MAIN).o $(SRC).o $(SRC1).o
	$(CXX) $^ -o $@
$(MAIN).o:$(MAIN).cpp
	$(CXX) $(FLAGS) $^
$(SRC).o:$(SRC).cpp
	$(CXX) $(FLAGS) $^
$(SRC1).o:$(SRC1).cpp
	$(CXX) $(FLAGS) $^
clean:
	rm -rf *.o *~ $(MAIN)
