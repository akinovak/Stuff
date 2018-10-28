echo "<h3>Grupe<h3><table border='1'>" >> Grupe.html
echo "<tr><td>group name</td><td>password</td><td>GID</td></tr>" >> Grupe.html

egrep '.*' /etc/group -o -h \
|sed -r 's/([a-zA-Z]+):([a-zA-Z]+):([0-9]+).*/<tr><td>\1<\/td><td>\2<\/td><td>\3<\/td>/' >> Grupe.html



echo "</body>" >> Grupe.htl 
echo "</html>" >> Grupe.html
