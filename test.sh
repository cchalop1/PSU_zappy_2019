#!/bin/bash
echo "start test"
make re
./zappy_server -x 10 -y 10 -c 2 -n name1 name2 -f 10 -p 4243 &
cd tests
npm i
npm test