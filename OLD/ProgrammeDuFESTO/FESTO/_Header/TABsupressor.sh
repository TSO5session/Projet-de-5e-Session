#!/bin/bash
find ./ -type f -exec sed -i 's/\t/   /g' {} \;


