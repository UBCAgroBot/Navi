MODULE_OBJS+= $(addprefix $(OBJS_DIR)/, $(GENERATED_OBJS))
BUILD_MODULES+= build_$(DIR)
CLEAN_MODULES+= clean_$(DIR)