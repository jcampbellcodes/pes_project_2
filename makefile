# Top level makefile. Delves into the Release and Debug subdirs and runs make on the specific targets contained.

# Builds all targets.
all: fb_run fb_debug pc_run pc_debug

# Builds the PC release build.
pc_run:
	cd Release && $(MAKE) output/pc_run

# Builds the FB release build.
fb_run:
	cd Release && $(MAKE) output/pes_project2.axf

# Builds the PC debug build.
pc_debug:
	cd Debug && $(MAKE) output/pc_debug

# Builds the FB debug build.
fb_debug:
	cd Debug && $(MAKE) output/pes_project2.axf

# Cleans both Debug and Release areas.
clean:
	cd Debug && $(MAKE) clean
	cd Release && $(MAKE) clean
