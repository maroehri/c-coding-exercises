MAIN_TEX = coding-exercises.tex
PARTS_DIR = parts
IMAGES_DIR = images
TEMP_EXT = aux log out toc

.PHONY: all clean

all: $(MAIN_TEX)
	lualatex -shell-escape $(MAIN_TEX)
	lualatex -shell-escape $(MAIN_TEX)
	make clean

$(MAIN_TEX): $(PARTS_DIR)/*.tex $(IMAGES_DIR)/*.pdf

$(IMAGES_DIR)/%.pdf: $(IMAGES_DIR)/%.tex
	cd $(IMAGES_DIR) && lualatex -shell-escape $(notdir $<)
	
clean:
	rm -f *.aux *.log *.out *.toc
	rm -f $(PARTS_DIR)/*.aux $(PARTS_DIR)/*.log $(PARTS_DIR)/*.out $(PARTS_DIR)/*.toc
	rm -f $(IMAGES_DIR)/*.aux $(IMAGES_DIR)/*.log $(IMAGES_DIR)/*.out $(IMAGES_DIR)/*.toc
