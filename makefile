all: fb_run fb_debug pc_run pc_debug

pc_run:
	cd Release && $(MAKE) output/pc_run

fb_run:
	cd Release && $(MAKE) output/pes_project2.axf

pc_debug:
	cd Debug && $(MAKE) output/pc_debug

fb_debug:
	cd Debug && $(MAKE) output/pes_project2.axf

clean:
	cd Debug && $(MAKE) clean
	cd Release && $(MAKE) clean
