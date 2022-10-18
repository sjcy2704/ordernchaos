BUILD_DIR = build

$(BUILD_DIR)/: main.cpp
				mkdir $@
				g++ -std=c++11 -o $@/OrderNChaos src/Helpers.cpp src/Board.cpp src/Player.cpp src/Person.cpp src/Game.cpp main.cpp

