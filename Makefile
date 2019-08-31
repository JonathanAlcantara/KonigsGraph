build:
	@mkdir -p bin
	@echo 'Compiling program'
	g++ src/konigs.cpp -o bin/konigs

run: build
	@echo $('\n\n')
	@bin/konigs

clean:
	@echo 'Cleaning project'
	@rm -r bin/*
