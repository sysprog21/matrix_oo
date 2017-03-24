EXEC = \
    tests/test-matrix

OUT ?= .build
.PHONY: all
all: $(OUT) $(EXEC)

CC ?= gcc
CFLAGS = -Wall -std=c99 -g -O0 -I.
LDFLAGS = -lpthread

OBJS := \
	matrix_naive.o

deps := $(OBJS:%.o=%.o.d)
OBJS := $(addprefix $(OUT)/,$(OBJS))
deps := $(addprefix $(OUT)/,$(deps))

tests/test-%: $(OBJS) tests/test-%.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OUT)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ -MMD -MF $@.d $<

$(OUT):
	@mkdir -p $@

check: $(EXEC)
	@for test in $^ ; \
	do \
		echo "Execute $$test..." ; $$test && echo "OK!\n" ; \
	done

clean:
	$(RM) $(EXEC) $(OBJS) $(deps)
	@rm -rf $(OUT)

-include $(deps)
