APPLICATION = oiLib_testapp

DIR_DEBUG = debug
DIR_RELEASE = release


all: build_release

build_debug:
	mkdir -p $(DIR_DEBUG)
	make compile_flags="-O0 -g" --directory=$(DIR_DEBUG) --makefile=../Makefile_Build

build_release:
	mkdir -p $(DIR_RELEASE)
	make compile_flags="-O3" --directory=$(DIR_RELEASE) --makefile=../Makefile_Build
	mkdir -p bin
	cp $(DIR_RELEASE)/main.bin bin/$(APPLICATION)
	

clean:
	rm -rf $(DIR_DEBUG)/main.bin 
	rm -rf $(DIR_DEBUG)/*.d 
	rm -rf $(DIR_DEBUG)/*.o 
	rm -rf $(DIR_RELEASE)/main.bin 
	rm -rf $(DIR_RELEASE)/*.d 
	rm -rf $(DIR_RELEASE)/*.o 
	rm -rf bin/$(APPLICATION)


