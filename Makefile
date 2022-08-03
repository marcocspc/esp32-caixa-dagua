#Check for python 3
PYTHON3_OK := $(shell type -P python3)
ifeq ('$(PYTHON3_OK)','')
    $(error package 'python3' not found)
endif

.DEFAULT_GOAL := info

.PHONY: prepare
prepare: clean;
	mkdir -p build/
	rsync -rupE src/ build/
	python3 scripts/substituir_includes_relativos.py

.PHONY: clean
clean:
	rm -rf build/ 

.PHONY: info 
info:
	@echo "Execute `make prepare` para que o código possa"
	@echo "ser preparado para compilação no Arduino IDE."

.PHONY: default
default: info ;
