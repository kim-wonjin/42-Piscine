mkdir ~/alias_setting 2> mkdir_error.txt
rm mkdir_error.txt
cp ./assignment_checker_bash.sh ~/alias_setting/assignment_check.sh
echo "alias check=\"~/alias_setting/assignment_check.sh\"" >> ~/.bashrc
source ~/.bashrc
