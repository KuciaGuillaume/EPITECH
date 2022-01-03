#!/bin/bash

cut -d ';' -f 3 | grep -w -a "$1" -c -i
