mkdir ~/alias_setting 2> mkdir_error.txt
rm mkdir_error.txt
cp ./assignment_checker.sh ~/alias_setting/assignment_check.sh
echo "alias check=\"~/alias_setting/assignment_check.sh\"" >> ~/.zshrc
source ~/.zshrc
