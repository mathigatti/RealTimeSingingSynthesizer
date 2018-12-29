git config --global user.email "740291272@qq.com"
git config --global user.name "740291272"
git status

echo ""
echo "pulling..."

git pull origin master

git status

echo ""
read -p "Enter commit message:"

rm *~
rm **/*~
rm **/**/*~

git add *
git stage *
git commit -a -m "${REPLY}"

git status

echo ""
echo "commit finished"

git gc
git push origin master

echo "hia hia I have finished"
