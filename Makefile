MAIN_TEX = coding-exercises.tex
PARTS_DIR = parts
TEMP_EXT = aux log out toc

.PHONY: all clean

all: $(MAIN_TEX)
	lualatex -shell-escape $(MAIN_TEX)
	lualatex -shell-escape $(MAIN_TEX)
	make clean

$(MAIN_TEX): $(PARTS_DIR)/*.tex

clean:
	rm -f *.aux *.log *.out *.toc
	rm -f parts/*.aux parts/*.log parts/*.out parts/*.toc
