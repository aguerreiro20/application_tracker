inputFile="applications.db"
if [ ! -f $inputFile ]
then
	echo "Input file '$inputFile' doesn't exist. Run the program first."
	exit -1
fi
NC='\033[0m' # No Color
RED='\033[0;31m'
AMBER='\033[0;33m'
GREEN='\033[0;32m'
threshold=1000
for line in `cat "$inputFile" | sed -e 's/ /___/g'`; do 
	if [ -z "${line##*ejected*}" ]
	then
		color=$RED;
		text=" x  "
  elif [ -z "${line##*wait*}" ]
	then
		color=$AMBER;
		text="--> "
	else
		color=$GREEN;
		text="==> "
	fi
	dispLine=`echo "$line" | sed -e 's/___/ /g' -e 's/|/ | /g'`
	printf "${NC}$text${color}$dispLine\n"
done
