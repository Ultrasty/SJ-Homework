@echo ���Լ�����ʼ����ʱԼһ�ְ��ӡ�^����ʱ���޷�Ӧ���볢�Դ�echo������
@echo ������ʾ�����bat�Ǹ�����������������õģ���Ӧ�ó�Ϊ�㲻��ϰʹ�ùܵ����ض�������ɡ�
@echo ��ע�⣺���β��Բ�����������
@echo off

echo >myresult.txt
echo >demoresult.txt

setlocal enabledelayedexpansion

::����Ҫ�ĵĵط��������
cd "D:\�ļ�\��\������\�ҵĸ߳���ҵ\����Ŀ¼"



set count=0
for /f "delims=^" %%i in (test-data.txt) do (
echo Data #!count! is %%i^ >>myresult.txt
echo %%i^ | my >>myresult.txt
set /a count+=1
)

set count=0
for /f "delims=^" %%i in (test-data.txt) do (
echo Data #!count! is %%i^ >>demoresult.txt
echo %%i^ | demo >>demoresult.txt
set /a count+=1
)

echo on

fc myresult.txt demoresult.txt

@pause