################################################################################
# Makefile 
# Jared Spaulding
# COSC 3750, SP 2020
# Homework 4
# Feb 20, 2020
# 
# Makefile to complile wycat.c
################################################################################

CC=gcc
CFLAGS=-ggdb -Wall
RM=/bin/rm -f

wycat: wycat.c
	$(CC) $(CFLAGS) $? -o wycat -I $(CURDIR)

clean: 
	$(RM) core.*
