QMAKE ?= qmake

default:
	mkdir -p build
	cd build && $(QMAKE) ../blusher-qt.pro -spec linux-g++ && make qmake_all
	cd build && make -j8

clean:
	rm -rf build
