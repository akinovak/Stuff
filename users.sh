egrep '[a-zA-Z]+:x:[0-9]+:[0-9]+:.*' /etc/passwd -o -h \
| sed -r 's/([a-zA-Z]+):x:([0-9]+):.*/\2 : \1/' \
| sort -k2 -r \
