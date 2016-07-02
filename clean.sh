#!/bin/bash
# deletes all no extension executable files
#find . -type f ! -name "*.*" -delete
#http://stackoverflow.com/questions/856463/how-to-remove-delete-executable-files-aka-files-without-extension-only
find . -type f -executable ! -name "*.*"
find . -type f -executable ! -name "*.*" -delete