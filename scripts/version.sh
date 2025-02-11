versionFile='src/version.h' # change this as per your own work space
gitCommitHash=`git rev-parse HEAD`
gitCommitMessage=`git log -1 --pretty=%B`
echo '#ifndef VERSION_H' > $versionFile
echo '#define VERSION_H' >> $versionFile
echo "const char GIT_COMMIT_HASH[]  = \"$gitCommitHash\";" >> $versionFile
echo "const char GIT_COMMIT_MESSAGE[]  = \"$gitCommitMessage\";" >> $versionFile
echo '#endif' >> $versionFile
