@echo ���Լ�����ʼ����ʱԼһ�ְ��ӡ�^����ʱ���޷�Ӧ���볢�Դ�echo������
@echo off

echo >myresult.txt
echo >demoresult.txt

cd "D:\�ļ�\��\������\�ҵĸ߳���ҵ\2021-10-28\4-b1_test-data��2000����������+�ο���bat�ļ���_by2152955"
for /f %%i in (test-data.txt) do echo %%i^ | my>>myresult.txt
for /f %%i in (test-data.txt) do echo %%i^ | demo >>demoresult.txt

echo on

echo n | comp myresult.txt demoresult.txt

@pause