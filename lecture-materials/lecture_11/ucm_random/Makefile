install:
	@cat new_settings.json > /home/me/.theia/settings.json
	@mkdir -p /home/me/inc/
	@cp ucm_random.h /home/me/inc/
	@mv /home/me/inc/ucm_random.h /home/me/inc/ucm_random
	@if [ $(shell cat /home/me/.bashrc | grep CPATH=/home/me/inc | wc -l) -eq 0 ]; then echo "export CPATH=/home/me/inc" >> /home/me/.bashrc; fi
	@echo "Installed <ucm_random> header"
	@echo "You can now use #include<ucm_random> in your C++ programs"