
all: Dish

Dish: Dish.o DishString.o CA4.o
	g++ Dish.o DishString.o CA4.o -o Dish

DishString.o: DishString.cpp
	g++ -c DishString.cpp

Dish.o: Dish.cpp
	g++ -c Dish.cpp

CA4.o: CA4.cpp
	g++ -c CA4.cpp

clean:
	rm -f *.o Dish
