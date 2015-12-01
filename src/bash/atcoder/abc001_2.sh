#!/bin/bash

bcValue() {
    echo $(echo $@ | bc)
}
bclValue() {
    echo $(echo $@ | bc -l)
}
isBcTrue() {
    if [ $(bcValue $@) -eq 1 ]
    then
        return 0
    else
        return 1
    fi
}
isBcFalse() {
    if [ $(bcValue $@) -eq 0 ]
    then
        return 0
    else
        return 1
    fi
}

read m
km=$(bclValue $m / 1000)
echo "km: $km"
# if [ $(echo "$km < 0.1" | bc) -eq 1 ]
if isBcTrue "$km < 0.1"
then
    v=0
else
    v=$(echo "10 * $km / 1" | bc)
fi
echo "v: $v"

