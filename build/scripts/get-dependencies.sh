#!/bin/sh

FILE="ft_deps.properties"

if [ "$1" ]
then
  cd "$1" || exit 1
fi

if [ -f "$FILE" ]
then
  cut -d "=" -f 1 "$FILE" | sed "s/^/ -lft_/"
fi
