
if [[ $1 == "clean" ]]; then
	rm -rf ./build/*
fi
cmake -S . -B ./build/
cd ./build/; make;
./2DGame

