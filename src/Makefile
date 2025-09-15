FLAGS=-Wall -Werror

all: rebuild

rebuild: clean build

build:
	g++ $(FLAGS) ./DeepLearn/Model.cpp  \
	./DeepLearn/Functions/*.cpp         \
	./DeepLearn/Layers/*.cpp  			\
	./main.cpp -o ../build/main

exec:
	../build/main

clean:
	rm -rf ../build/*

format:
	clang-format -n * \
	./Matrix/* \
	./DeepLearn/* \
	./DeepLearn/Functions/* \
	./DeepLearn/Layers/*


../build/test_mat.o:
	g++ -c ./Matrix/test_mat.cpp -o ../build/test_mat.o

matrix_test: clean ../build/test_mat.o
	g++ $(FLAGS) ../build/test_mat.o -o ../build/matrix_test
	../build/matrix_test