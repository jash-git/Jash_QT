#!/bin/bash 
#Filename: find_sh.sh

#印出目前目錄下 所有檔案和目錄
#find . -print

#印出目前目錄的上層 所有檔案和目錄
#find .. -print

#搜尋目錄下的所有『cpp』
#find . -name "*.cpp" -print

#搜尋目錄下的所有『h 和 cpp』
#find . \( -name "*.cpp" -o -name "*.h" \) -print

#搜尋目錄下的所有『h 和 cpp』並導入檔案中
#find . \( -name "*.cpp" -o -name "*.h" \) -print > findlog.txt
#find . -iregex ".*\(\.cpp\|\.h\)$" > findlog.txt

#只搜尋目錄
#find . -type d -print

#只搜尋檔案
#find . -type f -print
find . -type f \( -name "*.cpp" -o -name "*.h" \) -print

#依照檔案大小 修改時間 搜尋
#p42

#刪除匹配文件
#p43

#搜尋匹配權限文件
#p43

#複合式命令
#p43~p44


