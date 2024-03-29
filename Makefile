# Makefile_header
# https://ie.u-ryukyu.ac.jp/~e085739/c.makefile.tuts.html

# プログラム名とオブジェクトファイル名
PROGRAM = a.out
OBJS = main.o color.o frame.o draw.o

# 定義済みマクロの再定義
CC = gcc
CFLAGS = -Wall -O2

# サフィックスルール適用対象の拡張子の定義
.SUFFIXES: .c .o

# プライマリターゲット
.PHONY: all
all: depend $(PROGRAM)

# プログラムの生成ルール
$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $^

# サフィックスルール
.c.o:
	$(CC) $(CFLAGS) -c $<

# ファイル削除用ターゲット
.PHONY: clean
clean:
	$(RM) $(OBJS) depend.inc

# ヘッダファイルの依存関係
.PHONY: depend
depend: $(OBJS:.o=.c)
	-@ $(RM) depend.inc
	-@ for i in $^; do cpp -MM $$i | sed "s/\ [_a-zA-Z0-9][_a-zA-Z0-9]*\.c//g" >> depend.inc; done

-include depend.inc