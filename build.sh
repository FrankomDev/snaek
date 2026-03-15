if [[ $(ls /usr/lib/libraylib.so) ]]; then
	mkdir build
	cd build
	gcc ../src/main.c ../src/snake.c ../src/item.c ../src/state.c -lraylib -o snake && ./snake

else
	echo "You need Raylib!"
fi
