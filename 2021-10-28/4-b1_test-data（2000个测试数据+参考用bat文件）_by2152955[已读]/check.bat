@echo 测试即将开始，用时约一分半钟。^若长时间无反应，请尝试打开echo检查错误。
@echo off

echo >myresult.txt
echo >demoresult.txt

cd "D:\文件\课\大四上\我的高程作业\2021-10-28\4-b1_test-data（2000个测试数据+参考用bat文件）_by2152955"
for /f %%i in (test-data.txt) do echo %%i^ | my>>myresult.txt
for /f %%i in (test-data.txt) do echo %%i^ | demo >>demoresult.txt

echo on

echo n | comp myresult.txt demoresult.txt

@pause