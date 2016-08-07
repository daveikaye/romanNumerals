## Process this file with automake to produce Makefile.in

TESTS = check_roman_numerals
check_PROGRAMS = check_roman_numerals
check_roman_numerals_SOURCES = check_roman_numerals.c $(top_builddir)/src/roman_numerals.h
check_roman_numerals_CFLAGS = @CHECK_CFLAGS@
check_roman_numerals_LDADD = $(top_builddir)/src/libmoney.la @CHECK_LIBS@
