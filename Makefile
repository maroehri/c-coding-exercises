MAIN_TEX = coding-exercises.tex
PARTS_DIR = parts
IMAGES_DIR = images
TEMP_EXT = aux log out toc

# Find all .tex files in the IMAGES_DIR
IMAGE_TEX_FILES = $(wildcard $(IMAGES_DIR)/*.tex)

# Generate corresponding .pdf targets
IMAGE_PDF_FILES = $(IMAGE_TEX_FILES:.tex=.pdf)

.PHONY: all clean

all: $(MAIN_TEX) $(IMAGE_PDF_FILES)
	lualatex -shell-escape $(MAIN_TEX)
	lualatex -shell-escape $(MAIN_TEX)
	make clean

$(MAIN_TEX): $(PARTS_DIR)/*.tex $(IMAGE_PDF_FILES)

$(IMAGES_DIR)/%.pdf: $(IMAGES_DIR)/%.tex
	cd $(IMAGES_DIR) && lualatex -shell-escape $(notdir $<)
	
clean:
	rm -f *.aux *.log *.out *.toc
	rm -f $(PARTS_DIR)/*.aux $(PARTS_DIR)/*.log $(PARTS_DIR)/*.out $(PARTS_DIR)/*.toc
	rm -f $(IMAGES_DIR)/*.aux $(IMAGES_DIR)/*.log $(IMAGES_DIR)/*.out $(IMAGES_DIR)/*.toc
