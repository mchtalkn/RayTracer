all:
	g++ -std=c++11 -O3 -pthread ./*.cpp ./*.h -o raytracer
clean:
	rm -f *.gch *.o raytracer
