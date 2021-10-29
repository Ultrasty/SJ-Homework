@echo 测试即将开始，预计马上完成。^若长时间无反应，请尝试打开echo检查错误。
@echo 友情提示：这个bat是给你检查大量测试数据用的，不应该成为你不练习使用管道和重定向的理由。
@echo 请注意：本次测试不包括错误处理。
@echo off

echo >myresult.txt
echo >demoresult.txt

setlocal enabledelayedexpansion

::你需要改的地方在这里↓
cd "C:\Users\cinea\Documents\Tencent Files\1650121748\FileRecv\21221-040101-W0701.第04模块 作业 - PART1 - 基础函数分解练习\自检-月历"

set count=0
for /f "delims=^" %%i in (test-simpledata.txt) do (
echo Data #!count! is %%i^ >>myresult.txt
echo %%i^ | my >>myresult.txt
set /a count+=1
)

set count=0

for /f "delims=^" %%i in (test-simpledata.txt) do (
echo Data #!count! is %%i^ >>demoresult.txt
echo %%i^ | demo >>demoresult.txt
set /a count+=1
)

echo on

fc myresult.txt demoresult.txt

@pause