.PHONY: clean All

All:
	@echo "----------Building project:[ flameide - Debug ]----------"
	@$(MAKE) -f  "flameide.mk"
clean:
	@echo "----------Cleaning project:[ flameide - Debug ]----------"
	@$(MAKE) -f  "flameide.mk" clean
