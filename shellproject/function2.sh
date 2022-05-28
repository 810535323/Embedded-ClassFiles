grep_user()
{
	R=`grep "^$1:" /etc/passwd | wc -l`
	echo $R
}

echo -n  "input username:"
read USER
ret=`grep_user $USER`
if [ $ret -eq 1 ]
then
	echo "$USER exist"
else
	echo "$USER not exist"
fi
