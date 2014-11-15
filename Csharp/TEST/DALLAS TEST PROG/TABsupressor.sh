#!/bin/bash
echo ""
echo "This script will replace all tab with 3 spaces"
echo ""
find ./ -type f -exec sed -i 's/\t/   /g' {} \;
echo "Done!"



