#!/bin/bash

deb=$MY_LINE1
fin=$MY_LINE2

tac | cut -d ":" -f 1 | rev | sed -n '2~2p' | sort -r | sed -n "$deb, $fin p" | sed -z 's/\n/, /g' | sed 's/..$/.\n/'



